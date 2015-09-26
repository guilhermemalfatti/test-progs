#ifndef _GRAPH_HEADER
#define _GRAPH_HEADER

#define GRAPH_DATA_ELEMENT_TYPE int
#define GRAPH_DATA_ELEMENT_NAME data

#define GRAPH_DATA_ELEMENT_SET(GRAPH_NODE, SET_DATA_ELEM)\
	GRAPH_NODE->QUEUE_DATA_ELEMENT_NAME = SET_DATA_ELEM;

#define GRAPH_DATA_ELEMENT_INIT(GRAPH_NODE)\
	GRAPH_NODE->neighbours = NULL;\
	GRAPH_NODE->visited = 0;
	
#define GRAPH_DATA_ELEMENT_PRINT(GRAPH_NODE)\
	printf("%d", GRAPH_NODE->data)
// #define QUEUE_DATA_ELEMENT_CMP(LIST_NODE, CMP_DATA_ELEM) (\
// 	LIST_NODE->QUEUE_DATA_ELEMENT_NAME != CMP_DATA_ELEM)
// #define QUEUE_DATA_ELEMENT_PRINT(LIST_NODE) printf("Value: %d\n",LIST_NODE->QUEUE_DATA_ELEMENT_NAME);

struct process_fn_struct {
	struct s_graph_node *node1;
	struct s_graph_node *node2;
};

typedef struct s_graph_node {
	GRAPH_DATA_ELEMENT_TYPE GRAPH_DATA_ELEMENT_NAME;
	struct list_node *neighbours;
	short visited;
} GraphNode;

typedef struct s_graph {
	int count;
	struct s_graph_node *root;
} Graph;

#include "llist.h"

Graph* newGraph();
GraphNode* newGraphNode(Graph *g, GRAPH_DATA_ELEMENT_TYPE value);
void addNeighbourNode(GraphNode* neighbour, GraphNode* parent);
void BFSGraph(Graph *graph, void (*process_fn)(struct process_fn_struct), struct process_fn_struct);
void printGraph(Graph *graph);

#endif