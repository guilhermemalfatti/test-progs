#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "llist.h"

struct s_list* ll_new()
{
	struct s_list* new_list = malloc(sizeof(struct s_list));
	new_list->size = 0;
	new_list->head = NULL;
	new_list->tail = NULL;
	
	return new_list;
}

struct s_node *ll_new_node(void* value)
{
	struct s_node *new_node = malloc(sizeof(struct s_node));
	
	new_node->next = NULL;
	new_node->prev = NULL;
	new_node->data = value;
	
	return new_node;
}

void ll_enqueue(struct s_list *list, struct s_node *node)
{
	if (list->size == 0) {
		list->head = node;
		list->tail = node;
	} else {
		node->next = list->tail;
		list->tail->prev = node;
		list->tail = node;
	}
	
	list->size++;
	return;
}

struct s_node* ll_dequeue(struct s_list *list)
{
	if (list->size == 0)
		return NULL;
	
	struct s_node* retval = list->head;
	
	list->head = list->head->prev;;
	list->size--;
	if (list->head != NULL)
		list->head->next = NULL;
	
	return retval;
}

struct s_node* ll_get(struct s_list *list, int index)
{
	if (index >= list->size)
		return NULL;
	
	int i;
	struct s_node *aux = list->head;
	for(i = 0; i < index; i++) {
		aux = aux->prev;
	}
	
	return aux;
}

struct s_node* ll_get_head(struct s_list *list)
{
	return ll_get(list, 0);
}

struct s_node* ll_get_tail(struct s_list *list)
{
	return ll_get(list, list->size-1);
}

struct s_node* ll_search(struct s_list* list, void* data, int (*cmp_function)(void* a, void* b))
{
	struct s_node *pointer;

	pointer = list->head;
	while(pointer != NULL && cmp_function(pointer->data, data)) {
		pointer = pointer->prev;
	}
	return pointer;
}

struct s_node* ll_sort(struct s_list* list, int (*cmp_function)(void*, void*))
{
	struct s_node *node_to_sort = list->tail->next;
	struct s_node *aux;
	struct s_node *i;
	
	while(node_to_sort != NULL) {
		i = list->tail;
		
		int found = 0;
		while (i != NULL && i != node_to_sort) {
			if (cmp_function(i->data, node_to_sort->data) <= 0) {
				i = i->next;
			} else {
				/** node_to_sort must be inserted right before i */
				/** (..., i_prev, i, i_next, ..., node_prev, node_to_sort, node_next, ...) */
				struct s_node *i_prev = i->prev;
				struct s_node *i_next = i->next;
				struct s_node *node_prev = node_to_sort->prev;
				struct s_node *node_next = node_to_sort->next;
				
				if (i_prev != NULL)
					i_prev->next = node_to_sort;
				else
					list->tail = node_to_sort;
				
				node_to_sort->prev = i_prev;
				node_to_sort->next = i;
				
				i->prev = node_to_sort;
				
				node_prev->next = node_next;
				if (node_next != NULL)
					node_next->prev = node_prev;
				else
					list->head = node_prev;
				
				found = 1;
				node_to_sort = node_next;
				break;
			}
		}
		
		if (found == 0)
			node_to_sort = node_to_sort->next;
		
		/* If node_to_sort comes to tail position, fix it and update tail. */ 
// 		if (i == NULL && node_to_sort != list->tail) {
// 			node_to_sort->prev->next = node_to_sort->next;
// 			node_to_sort->next->prev = node_to_sort->prev;
// 			
// 			node_to_sort->prev = NULL;
// 			node_to_sort->next = list->tail;
// 			
// 			list->tail->prev = node_to_sort;
// 			
// 			list->tail = node_to_sort;
// 		}
	}
}

void ll_free(struct s_node* l)
{
	struct s_node* aux = l;
	while(aux != NULL) {
		aux = l->next;
		free(l);
		l = aux;
	}
}
