#include<stdio.h> //FILE
#include<stdlib.h> //rand
#include<time.h>

typedef struct{
	float peso;
	float volume;
	float cor;
	float posicao;
	float textura;
	float consistencia;
	float temperatura;
	float idade;
	char especie;
} fruta;

int main(){
	float finalBias;
	fruta amostra[30];
	srand(time(0));

	//busca os valores no arquivo e armazena em um array 'amostra'
	FILE *fp=fopen("entradas2.txt","r");
	for(int x=0;x<30;x++)fread(&amostra[x],sizeof(fruta),1,fp);
	fclose(fp);

	finalBias=3.50+(((float)rand()/(float)(RAND_MAX))/1.0);

	for(int x=0;x<1000000;x++){ //ajusta os bias centenas de vezes
		int alguma=rand()%30; //escolhe uma maca qualquer

		float caracteristica[8]={amostra[alguma].peso,amostra[alguma].volume,amostra[alguma].cor,amostra[alguma].posicao,amostra[alguma].textura,amostra[alguma].consistencia,amostra[alguma].temperatura,amostra[alguma].idade};

		float referencia=0;
		for(int t=0;t<8;t++)referencia+=caracteristica[t];

		//ajusta os bias pouco a pouco
		if(referencia>finalBias)finalBias=finalBias+(finalBias*0.000001); //um pouco a mais
		else if(referencia<finalBias)finalBias=finalBias-(finalBias*0.000001); //um pouco a menos
		
		printf("finalBias = %f\n",finalBias);

	}

	fp=fopen("bias1.txt","w");
	fprintf(fp,"%f\n",finalBias); //grava no arquivo o bias final
	fclose(fp);

	return 0;
}

