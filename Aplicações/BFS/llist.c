#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "llist.h"

ListNode *newListNode(LIST_DATA_ELEMENT_TYPE value) {
	ListNode *new_node = (ListNode*) calloc(1, sizeof(ListNode));
#ifdef LIST_DATA_ELEMENT_INIT
	LIST_DATA_ELEMENT_INIT(new_node)
#endif
	new_node->next = NULL;
	LIST_DATA_ELEMENT_SET(new_node, value);
	return new_node;
}
//ListNode *auxPointer;
void insertFirstElementInList(ListNode **list, ListNode *node) {
	register ListNode *pointer = *list;
    register ListNode *auxPointer;

	auxPointer = *list;
	*list = node;
	node->next = auxPointer;
	return;
}

void insertLastElementInList(ListNode **list, ListNode *node) {
	register ListNode *pointer = *list;
	register ListNode *auxPointer;

	if (pointer == NULL || !LIST_DATA_ELEMENT_SORT_COND(pointer, node)) {
		auxPointer = *list;
		*list = node;
		node->next = auxPointer;
		return;
	}

	while (pointer != NULL) {
		auxPointer = pointer;
		pointer = pointer->next;
	}

	auxPointer->next = node;
	return;
}

void insertNodeInSortedList(ListNode **list, ListNode *node) {
	register ListNode *pointer = *list;
	register ListNode *auxPointer;

	if (pointer == NULL || !LIST_DATA_ELEMENT_SORT_COND(pointer, node)) {
		auxPointer = *list;
		*list = node;
		node->next = auxPointer;
		return;
	}

	pointer = *list;
	auxPointer = pointer;
	while (pointer != NULL && LIST_DATA_ELEMENT_SORT_COND(pointer, node)) {
		auxPointer = pointer;
		pointer = pointer->next;
	}

	if (pointer == NULL) {
		auxPointer->next = node;
	} else {
		auxPointer->next = node;
		node->next = pointer;
	}
}

LIST_DATA_ELEMENT_TYPE getListNodeElement(ListNode* ln)
{
	return ln->LIST_DATA_ELEMENT_NAME;
}
//ListNode *pointer;
ListNode* searchList(ListNode *list, LIST_DATA_ELEMENT_TYPE search_key){
	register ListNode *pointer;

	pointer = list;
	while(pointer != NULL && LIST_DATA_ELEMENT_CMP(pointer, search_key)) {
		pointer = pointer->next;
	}
	return pointer;
}

// void printList(ListNode *list) {
// 	while(list != NULL){
// 		LIST_DATA_ELEMENT_PRINT(list);
// 		list = list->next;
// 	}
// 	printf("\n\n");
// }
