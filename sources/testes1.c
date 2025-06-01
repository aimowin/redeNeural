#include<stdio.h> //FILE
#include<stdlib.h> //rand
#include<time.h>

int main(){
	char especie;
	int laranjacerto=0,laranjaerrado=0,qqrcerto=0,qqrerrado=0;
	float referenciaFinal,finalBias;
	float bias[3],referencia;
	float peso,volume,cor,posicao,textura,consistencia,temperatura,idade;
	srand(time(0));

	//inicializa os bias com valores buscados do txt
	FILE *fp=fopen("bias1.txt","r");
	for(int x=0;x<3;x++)fscanf(fp,"%f\n",&bias[x]); //busca no arquivo o valor dos bias
	fscanf(fp,"%f\n",&finalBias); //busca no arquivo o valor do bias final
	fclose(fp);

	for(int x=0;x<1000;x++){
		if(rand()%2==0){
			especie='l';

			peso=0.8+((float)rand()/(float)(RAND_MAX))/10.0; //valor entre .8 e .9
			volume=0.7+((float)rand()/(float)(RAND_MAX))/10.0; //valor entre .7 e .8
			cor=0.6+((float)rand()/(float)(RAND_MAX))/10.0; //valor entre .6 e .7
			posicao=0.5+((float)rand()/(float)(RAND_MAX))/10.0; //valor entre .5 e .6
			textura=0.4+((float)rand()/(float)(RAND_MAX))/10.0; //valor entre .4 e .5
			consistencia=0.3+((float)rand()/(float)(RAND_MAX))/10.0; //valor entre .3 e .4
			temperatura=0.2+((float)rand()/(float)(RAND_MAX))/10.0; //valor entre .2 e .3
			idade=0.1+((float)rand()/(float)(RAND_MAX))/10.0; //valor entre .1 e .2
		}else{
			especie='q';

			peso=((float)rand()/(float)(RAND_MAX))/0.5; //valor entre 0 e 2
			volume=((float)rand()/(float)(RAND_MAX))/0.5; //valor entre 0 e 2
			cor=((float)rand()/(float)(RAND_MAX))/0.5; //valor entre 0 e 2
			posicao=((float)rand()/(float)(RAND_MAX))/0.5; //valor entre 0 e 2
			textura=((float)rand()/(float)(RAND_MAX))/0.5; //valor entre 0 e 2
			consistencia=((float)rand()/(float)(RAND_MAX))/0.5; //valor entre 0 e 2
			temperatura=((float)rand()/(float)(RAND_MAX))/0.5; //valor entre 0 e 2
			idade=((float)rand()/(float)(RAND_MAX))/0.5; //valor entre 0 e 2
		}

		referencia=(peso+volume+cor+posicao+textura+consistencia+temperatura+idade);

		referenciaFinal=((referencia*bias[0])+(referencia*bias[1])+(referencia*bias[2]));

		//printf("O valor obtido: %f | O valor esperado: %f\n",referenciaFinal,finalBias);

		referencia=referenciaFinal-finalBias;
		if(especie=='l'){
			if(referencia>-5&&referencia<5)laranjacerto++;else laranjaerrado++;
		}else{
			if(referencia>-5&&referencia<5)qqrerrado++;else qqrcerto++;
		}
	}

	printf("\n%d tentativas:\n",(laranjacerto+laranjaerrado+qqrcerto+qqrerrado));
	printf("Esperado laranja dado laranja: %d\n",laranjacerto);
	printf("Esperado laranja dado qqr: %d\n",laranjaerrado);
	printf("Esperado qqr dado qqr: %d\n",qqrcerto);
	printf("Esperado qqr dado laranja: %d\n\n",qqrerrado);

	return 0;
}

