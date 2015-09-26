#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lqueue.h"

Queue* newQueue()
{
	Queue* ret = malloc(sizeof(Queue));
	ret->size = 0;
	ret->head = NULL;
	ret->tail = NULL;

	return ret;
}

QueueNode* newQueueNode(QUEUE_DATA_ELEMENT_TYPE value) {
	QueueNode *new_node = calloc(1, sizeof(QueueNode));
#ifdef QUEUE_DATA_ELEMENT_INIT
	QUEUE_DATA_ELEMENT_INIT(new_node)
#endif
	new_node->next = NULL;
	new_node->prev = NULL;
	QUEUE_DATA_ELEMENT_SET(new_node, value)

	return new_node;
}

void enQueue(Queue *queue, QueueNode *node) {

	if (queue->tail == NULL) {
		queue->tail = node;
		queue->head = node;
	} else {
		node->next = queue->tail;
		queue->tail->prev = node;
		queue->tail = node;
	}

	queue->size++;
	return;
}
//QueueNode *ret;
QueueNode* deQueue(Queue *queue)
{
	register QueueNode *ret;

	if (queue->head == NULL) {
		return NULL;
	} else {
		ret = queue->head;
		queue->head = queue->head->prev;
		ret->prev = NULL;
		if (queue->head != NULL)
			queue->head->next = NULL;

		queue->size--;
		return ret;
	}
}

QueueNode *getQueueHead(Queue *queue)
{
	if (queue->head == NULL)
		return NULL;
	else
		return queue->head;
}

QUEUE_DATA_ELEMENT_TYPE getQueueNodeElement(QueueNode *qn)
{
	return qn->QUEUE_DATA_ELEMENT_NAME;
}

// void printQueue(Queue* queue) {
// 	QueueNode *aux = queue->tail;
//
// 	while(aux != NULL){
// 		QUEUE_DATA_ELEMENT_PRINT(aux);
// 		aux = aux->next;
// 	}
// 	printf("\n\n");
// }
