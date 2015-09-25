#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

char *help_msg="Random input generator for LinkedList.\nUsage: %s <num_inputs>.\n";

int main(int argc, char **argv)
{
	if (argc != 2) {
		fprintf(stderr, help_msg, argv[0]);
		return -1;
	}
		
	int i, size=0;
	
	srand(time(NULL));
	size = atoi(argv[1]);
	
	for (i=0; i < size; i++) {
		printf("%d\n", rand());
	}
}
