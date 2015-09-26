/*!
* @file listfunc.h
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
* Compilar com:
* gcc -Wall main.c listfunc.c -oversaoX
*
* Testar memória com:
* valgrind --tool=memcheck --leak-check=yes --show-reachable=yes ./versaoX
*/

#ifndef LISTFUNC_H
#define LISTFUNC_H


typedef struct _lista Lista;
/*!
* @brief Estrutura que define um nó da lista
*/
struct _lista {
   int dado;
   Lista *prox;
};

/*! @brief Inicialização
*/
Lista* inicializa(void);

/*! @brief Inserção de elemento na lista, com retorno de ponteiro
*/
Lista* insere_simples(int dado, Lista* lst);

/*! @brief Inserção de elemento na lista, usando ponteiro para ponteiro como parâmetro
*/
void insere(int dado, Lista** lst);

/*! @brief Impressão de todos os elementos
*/
void imprime(Lista* lst);

/*! @brief Desaloca todos os elementos da lista
*/
void libera(Lista* lst);

/*! @brief Busca um elemento da lista a partir de uma entrada
*/
Lista* busca(Lista* lst, int dado);

/*! @brief Remove um elemento da lista a partir de uma entrada. Retorna 1 se sucesso e 0 se não encontrado
*/
int apaga(Lista** lst, int dado);

/*! @brief Insere elemento em ordem
*/
void insere_ordenado (int dado, Lista** lst);

#endif
