#include<stdio.h> //FILE
#include<stdlib.h> //rand
#include<time.h>

int main(){
	FILE * fp; //para lidar com arquivos
	int imagens=120; //qtd de imagens para treinar
	char cor; //usada na conversao
	float bias=1;
	float amostra[imagens];
	char filename[25];

	for(int i=0;i<imagens;i++){
		sprintf(filename,"imagens/amostra%04d.bmp",i);
		fp=fopen(filename,"r");
		fseek(fp,54,SEEK_SET);
		amostra[i]=0.0;

		for(int l=0;l<60;l++)for(int x=0;x<60;x++)for(int y=0;y<3;y++){
			fread(&cor,sizeof(char),1,fp);
			amostra[i]+=(float)cor;
		}
		fclose(fp);
	}
	//for(int i=0;i<imagens;i++)printf("%f\n",amostra[i]);

	for(int x=0;x<300000;x++){ //ajusta o bias centenas de vezes
		int alguma=rand()%imagens; //escolhe uma imagem qualquer da amostra

		//printf("%d) %f\n",alguma,amostra[alguma]);

		//ajusta o bias pouco a pouco
		if(amostra[alguma]>bias)bias=bias+(bias*0.0001); //um pouco a mais
		else if(amostra[alguma]<bias)bias=bias-(bias*0.0001); //um pouco a menos

		printf("bias: %f\n",bias);
	}
	//printf("O valor que diferencia (bias): %f\n",bias);

	fp=fopen("bias2.txt","w");
	fprintf(fp,"%f\n",bias); //grava no arquivo o bias final
	fclose(fp);

	return 0;
}

