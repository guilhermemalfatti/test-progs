#ifndef _LINKED_LIST_HEADER
#define _LINKED_LIST_HEADER

struct s_list {
	int size;
	
	struct s_node *head;
	struct s_node *tail;
};

struct s_node {
	void* data;
	struct s_node* next;
	struct s_node* prev;
};

struct s_list* ll_new();
struct s_node* ll_new_node(void*);
void ll_enqueue(struct s_list*, struct s_node*);
struct s_node* ll_search(struct s_list*, void*, int (*)(void*, void*));
struct s_node* ll_get(struct s_list*, int);
struct s_node* ll_get_head(struct s_list *);
struct s_node* ll_get_tail(struct s_list *);
struct s_node* ll_dequeue(struct s_list *);

struct s_node* ll_sort(struct s_list*, int (*)(void*, void*));

void ll_free(struct s_node*);

#endif


