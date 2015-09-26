#ifndef _LINKED_LIST_HEADER
#define _LINKED_LIST_HEADER

#define LIST_DATA_ELEMENT_TYPE struct s_graph_node*
#define LIST_DATA_ELEMENT_NAME data

#define LIST_DATA_ELEMENT_INIT(LIST_NODE)\
	(LIST_NODE)->LIST_DATA_ELEMENT_NAME = NULL;
	
#define LIST_DATA_ELEMENT_SET(LIST_NODE, SET_DATA_ELEM) \
	LIST_NODE->LIST_DATA_ELEMENT_NAME = SET_DATA_ELEM;
	
/** Returns true if the first element precedes the second. */
#define LIST_DATA_ELEMENT_SORT_COND(AUX, CMP_DATA_ELEM) (\
	AUX->data < CMP_DATA_ELEM->data)
	
#define LIST_DATA_ELEMENT_CMP(LIST_NODE, CMP_DATA_ELEM) (\
	LIST_NODE->data != CMP_DATA_ELEM)
	
#define LIST_DATA_ELEMENT_PRINT(LIST_NODE) printf("Value: %d\n",LIST_NODE->data);

typedef struct list_node {
	struct list_node *next;
	LIST_DATA_ELEMENT_TYPE LIST_DATA_ELEMENT_NAME;
} ListNode;

#include "graph.h"

ListNode *newListNode(LIST_DATA_ELEMENT_TYPE);
void insertFirstElementInList(ListNode **list, ListNode *node);
void insertNodeInSortedList(ListNode**, ListNode*);
LIST_DATA_ELEMENT_TYPE getListNodeElement(ListNode*);
ListNode *searchList(ListNode*, LIST_DATA_ELEMENT_TYPE);
// void printList(ListNode*);

#endif


