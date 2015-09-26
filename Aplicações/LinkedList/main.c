#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "llist.h"

struct s_list *my_list = NULL;

char *help_msg = "LinkedList. \nUsage: %s <input_file> <num. of elements>.\n\
	The input file should contain the (integer) elements, one per line.\n";
//int a_int;
//int b_int;
int cmp_function(void *a, void *b)
{
	register int a_int = *(int*) a;
	register int b_int = *(int*) b;
    a_int = *(int*) a;
    b_int = *(int*) b;
	if (a_int < b_int) return -1;
	else if (a_int == b_int) return 0;
	else return 1;
}
//char *filename;
//int input_size;
//int *my_elements;
//int i;
//struct s_list *my_list;
int main(int argc, char **argv)
{
	if (argc != 3) {
		printf(help_msg, argv[0]);
		return -1;
	}
//filename = argv[1];
//input_size = atoi(argv[2]);
//my_list = ll_new();
//my_elements = malloc(sizeof(int)*input_size);
	register char *filename = argv[1];
	register int input_size = atoi(argv[2]);

	register struct s_list *my_list = ll_new();
	register int *my_elements = malloc(sizeof(int)*input_size);
    register int i;
	/* Reads elements from file. */
	FILE *input_file = fopen(filename, "r");
	char buffer[22] = {'\0'};
	for ( i = 0; i < input_size; i++) {
		fgets(buffer, 21, input_file);
		my_elements[i] = atoi(buffer);
#ifdef DEBUG
		printf("Input[%d] = %d\n", i, my_elements[i]);
#endif
	}
	fclose(input_file);

	/* Inserts the elements in the list. */
	for ( i = 0; i < input_size; i++) {
		ll_enqueue(my_list, ll_new_node(&my_elements[i]));
	}

	ll_sort(my_list, &cmp_function);

#ifdef DEBUG
	struct s_node* my_node = my_list->tail;
	printf("Sorted list:\n");
	while (my_node != NULL) {
		printf("%d\n", *(int*) my_node->data);
		my_node = my_node->next;
	}
#endif

	/* Searches the list for each of the elements. */
	for( i=0; i < input_size; i++) {
		struct s_node* my_node = ll_search(my_list, &my_elements[i], &cmp_function);
		if (my_node != NULL) {
			printf("Found element: %d @ %p\n", *(int*) my_node->data, my_node);
		}
	}

	return 0;
}
