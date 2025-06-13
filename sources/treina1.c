#include<stdio.h> //FILE
#include<stdlib.h> //rand
#include<time.h>

typedef struct{
	float peso;
	char especie;
} fruta;

int main(){
	fruta amostra[50];
	srand(time(0));

	//busca os valores no arquivo e armazena em um array 'amostra'
	FILE *fp=fopen("entradas1.txt","r");
	for(int x=0;x<50;x++){
		fscanf(fp,"%f %c\n",&amostra[x].peso,&amostra[x].especie); //busca no arquivo
		//printf("%2d) %f %c\n",x,amostra[x].peso,amostra[x].especie); //exibe na tela
	}
	fclose(fp);

	//inicializa o bias com um valor aleatorio
	float bias=((float)rand()/(float)(RAND_MAX))/1.0; //valor entre 0 e 1

	for(int x=0;x<4000;x++){ //ajusta o bias centenas de vezes
		int alguma=rand()%25; //escolhe uma laranja qualquer da amostra

		//printf("%d) [%c] %f\n",alguma,amostra[alguma].especie,amostra[alguma].peso);

		//ajusta o bias pouco a pouco
		if(amostra[alguma].peso>bias)bias=bias+(bias*0.01); //um pouco a mais
		else if(amostra[alguma].peso<bias)bias=bias-(bias*0.01); //um pouco a menos

		//printf("bias: %f\n",bias);
	}
	printf("O valor que diferencia (bias): %f\n",bias);

	return 0;
}

