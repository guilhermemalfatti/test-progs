#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

Graph *myGraph;

char *help_msg = "BFS algorithm.\nUsage: %s <input_size>\n";

void process(struct process_fn_struct params)
{
	if (!(getGraphNodeElement(params.node1) % getGraphNodeElement(params.node2))) {
#ifdef DEBUG
		printf("New edge from (%d) to (%d).\n", getGraphNodeElement(params.node2),  getGraphNodeElement(params.node1));
#endif
		addNeighbourNode(params.node2, params.node1);
	}
}
//int i;
//int input_size;
int main(int argc, char **argv)
{

	struct process_fn_struct params;

	if (argc != 2) {
		fprintf(stderr, help_msg, argv[0]);
		return -1;
	}
	register int input_size = atoi(argv[1]);
    register int i;
    input_size = atoi(argv[1]);
	myGraph = newGraph();

	myGraph->root = newGraphNode(myGraph, 1);
	for(i = 2; i < input_size; i++) {
		params.node1 = newGraphNode(myGraph, i);
		BFSGraph(myGraph, process, params);
	}
    printf("finish:\n");
	//printGraph(myGraph);
}
