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

	arq = fopen(url, "r");
	if(arq == NULL)
			printf("Erro, nao foi possivel abrir o arquivo\n");
	else
	while( (fscanf(arq,"%s %lu\n", nome, &valor))!=EOF ){
		if(strstr(nome, key)){
			printf("[BFS]nome: %s valor orinal: 702578775 valor: %lu calculo: %lu\n", nome, valor, (valor * 100)/702578775);
		}
		if(strstr(nome, key02)){
			printf("[BFS]nome: %s valor orinal: 691739700 valor: %lu calculo: %lu\n", nome, valor, (valor * 100)/691739700);
		}
	}

	fclose(arq);

	return 0;
}
