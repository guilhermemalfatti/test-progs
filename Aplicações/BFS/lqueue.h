#ifndef _QUEUE_HEADER
#define _QUEUE_HEADER

#define QUEUE_DATA_ELEMENT_TYPE struct s_graph_node*
#define QUEUE_DATA_ELEMENT_NAME data

#define QUEUE_DATA_ELEMENT_SET(QUEUE_NODE, SET_DATA_ELEM) \
	QUEUE_NODE->data = SET_DATA_ELEM;

#define QUEUE_DATA_ELEMENT_PRINT(QUEUE_NODE)\
	printf("%d", QUEUE_NODE->data)

typedef struct s_queue_node {
	struct s_queue_node *prev;
	struct s_queue_node *next;
	QUEUE_DATA_ELEMENT_TYPE QUEUE_DATA_ELEMENT_NAME;
} QueueNode;

typedef struct {
	int size;
	struct s_queue_node *head;
	struct s_queue_node *tail;
} Queue;

#include "graph.h"

Queue* newQueue();
QueueNode* newQueueNode(QUEUE_DATA_ELEMENT_TYPE);
void enQueue(Queue *queue, QueueNode *node);
QueueNode* deQueue(Queue *queue);
QueueNode *getQueueHead(Queue *queue);
QUEUE_DATA_ELEMENT_TYPE getQueueNodeElement(QueueNode *qn);
// void printQueue(Queue* queue);

#endif