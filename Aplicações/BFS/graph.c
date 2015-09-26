#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lqueue.h"

Graph* newGraph()
{
	register Graph* ret = malloc(sizeof(Graph));
	ret->root = NULL;

	return ret;
}

GraphNode* newGraphNode(Graph *g, GRAPH_DATA_ELEMENT_TYPE value) {
	GraphNode *new_node = calloc(1, sizeof(GraphNode));
#ifdef GRAPH_DATA_ELEMENT_INIT
	GRAPH_DATA_ELEMENT_INIT(new_node);
#endif
	GRAPH_DATA_ELEMENT_SET(new_node, value)

	g->count++;
	return new_node;
}

void addNeighbourNode(GraphNode* parent, GraphNode* neighbour)
{
	insertFirstElementInList(&parent->neighbours, newListNode(neighbour));
	return;
}

GRAPH_DATA_ELEMENT_TYPE getGraphNodeElement(GraphNode* gn)
{
	return gn->GRAPH_DATA_ELEMENT_NAME;
}
//	GraphNode *child_node;
//	ListNode *neighbours;
//	QueueNode *qn;
//	Queue *q;
void BFSGraph(Graph *graph, void (*process_fn)(struct process_fn_struct), struct process_fn_struct params)
{
	register Queue *q = newQueue();

	register QueueNode *qn;
	register GraphNode *parent_node = graph->root;
	register GraphNode *child_node;
	register ListNode *neighbours;

	unsigned short *visited = calloc(graph->count, sizeof(unsigned short));
	params.node2 = parent_node;
	process_fn(params);

	visited[parent_node->data] = 1;
	enQueue(q, newQueueNode(parent_node));

	while(getQueueHead(q)) {
		qn = deQueue(q);
		child_node = getQueueNodeElement(qn);
		neighbours = parent_node->neighbours;
		while (neighbours != NULL) {
			child_node = getListNodeElement(neighbours);
			if (!visited[child_node->data]) {
				params.node2 = child_node;
				process_fn(params); // Process node
				enQueue(q, newQueueNode(child_node));
				visited[child_node->data] = 1;
			}
			neighbours = neighbours->next;
		}
	}

	free(visited);
}
//GraphNode *child_node;
//ListNode *neighbours;
//Queue *q ;
void printGraph(Graph *graph)
{
	register Queue *q = newQueue();

	register QueueNode *qn;
	register GraphNode *parent_node = graph->root;
	register GraphNode *child_node;
	register ListNode *neighbours;

	unsigned short *visited = calloc(graph->count, sizeof(unsigned short));

	visited[parent_node->data] = 1;
	enQueue(q, newQueueNode(parent_node));
	printf("Visited node [%d].\n", parent_node->data);

	while(getQueueHead(q)) {
		qn = deQueue(q);
		child_node = getQueueNodeElement(qn);
		neighbours = parent_node->neighbours;
		while (neighbours != NULL) {
			child_node = getListNodeElement(neighbours);
			if (!visited[child_node->data]) {
				enQueue(q, newQueueNode(child_node));
				visited[child_node->data] = 1;
				printf("Visited node [%d].\n", child_node->data);
			}
			neighbours = neighbours->next;
		}
	}

	free(visited);
}
