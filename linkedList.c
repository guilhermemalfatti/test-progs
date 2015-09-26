#include <stdio.h>
#include <string.h>

int main(void)
{
	char key[] = "0.totalEnergy";
	char key02[] = "1.totalEnergy";
	char url[]="../../m5out/stats.txt",
	     info[500], nome[500];
	long valor;
	FILE *arq;
printf("bgin\n");
	arq = fopen(url, "r");
	if(arq == NULL)
			printf("Erro, nao foi possivel abrir o arquivo\n");
	else
	while( (fscanf(arq,"%s %lu\n", nome, &valor))!=EOF ){
		if(strstr(nome, key)){
			printf("[LL]nome: %s valor orinal: 187639740 valor: %lu calculo: %lu\n", nome, valor, (valor * 100)/187639740);
		}
		if(strstr(nome, key02)){
			printf("[LL]nome: %s valor orinal: 163679265 valor: %lu calculo: %lu\n", nome, valor, (valor * 100)/163679265);
		}
	}

	fclose(arq);

	return 0;
}
