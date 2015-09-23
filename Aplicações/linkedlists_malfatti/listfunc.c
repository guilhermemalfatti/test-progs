/*!
* @file listfunc.c
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

Lista* inicializa(void) {
   return NULL;
}

Lista* insere_simples(int dado, Lista* lst) {
   Lista* novo = (Lista*) malloc(sizeof(Lista));
   if (novo==NULL) {
     exit(EXIT_FAILURE);
   }
   novo->dado = dado;
   novo->prox = lst;
   return novo;
}

void insere(int dado, Lista** lst) {
   Lista* novo = (Lista*) malloc(sizeof(Lista));
   if (novo==NULL) {
     exit(EXIT_FAILURE);
   }
   novo->dado = dado;
   novo->prox = *lst;
   *lst=novo;   
}

void imprime(Lista* lst) {
   Lista *p;
   int k=0;
   printf("n\tend\t\tdado\tprox\n");
   for (p=lst; p!=NULL; p=p->prox) {
      printf("%d\t%p\t%d\t%p\n", k, p, p->dado, p->prox);
      k++;
   }
   printf("----------------------------------------------\n");
}

void libera(Lista* lst) {
   Lista* p = lst;
   while (p != NULL) {
      Lista* t=p->prox; /* guarda referência para o próximo elemento*/
      free(p); /* libera a memória apontada por p */
      p = t; /* faz p apontar para o próximo */
   }
}

Lista* busca (Lista* lst, int dado) {
  Lista* p;
  for (p=lst; p!=NULL; p=p->prox) {
    if (p->dado == dado) {
      return p;
    }
  }
  return NULL; /* se não achou o elemento, retorna nulo */
}

int apaga(Lista** lst, int dado) {
  Lista* ant = NULL; /*ponteiro para elemento anterior */
  Lista* p = *lst;/*ponteiro para percorrer a lista*/

  /* procura elemento na lista, guardando anterior */
  while (p != NULL && p->dado != dado) {
    ant = p;
    p = p->prox;
  }
  /* verifica se achou elemento */
  if (p == NULL)
    return 0; /* não achou: retorna 0 */

  /* retira elemento */
  if (ant == NULL) {
  /* retira elemento do inicio */
    *lst = p->prox;
  }
  else {
    /* retira elemento do meio da lista */
    ant->prox = p->prox;
  }
  free(p);
  return 1;/*sucesso*/
}

/* função auxiliar: cria e inicializa um nó */
Lista* cria (int dado) {
  Lista* novo = (Lista*) malloc(sizeof(Lista));
  if (novo==NULL) {
    exit(EXIT_FAILURE);
  }
  novo->dado = dado;
  return novo;
}

/* função insere_ordenado: insere elemento em ordem */
void insere_ordenado (int dado, Lista** lst) {
  Lista* novo = cria(dado); /* cria novo nó */
  Lista* ant = NULL; /* ponteiro para elemento anterior */
  Lista* p = *lst;  /* ponteiro para percorrer a lista*/
  /* procura posição de inserção */
  while (p != NULL && p->dado < dado) {
    ant = p;
    p = p->prox;
  }
  /* insere elemento */
  if (ant == NULL) {
  /* insere elemento no início */
    novo->prox = *lst;
    *lst = novo;
  }
  else {
    /* insere elemento no meio da lista */
    novo->prox = ant->prox;
    ant->prox = novo;
  }
}

