/*!
* @file main.c
* @author Fernando S. Pacheco
* @date 2015-03-16
* @brief Lista encadeada - Baseado no material de Celes e Rangel Cap. 10
*
* Parte 1:
*  Inicialização, inserção, impressão, liberação
* Parte 2:
*  Usando ponteiro para ponteiro (insere2)
* Parte 3:
*  Funções de busca e remoção
* Parte 4:
*  Inserção ordenada
*
*/

#include "listfunc.h"
#include <stdio.h>
#include <stdlib.h>


int main(void)
{
   Lista *lst = inicializa();
   Lista *b = NULL; 
   printf("##%p##\n",&lst);
   imprime(lst);
   insere_ordenado(100, &lst);
   insere_ordenado(97, &lst);
   insere_ordenado(42, &lst);
   insere_ordenado(250, &lst);
   imprime(lst);
   b=busca(lst, 99);
   if (b!=NULL) printf("Encontrado: %d\n", b->dado);
   if (apaga(&lst, 99)) {
     printf("Elemento removido\n");
   }
   else {
     printf("Elemento não encontrado\n");
   }
   imprime(lst);
   libera(lst);
   lst=NULL;
   imprime(lst);

   return EXIT_SUCCESS;
}
