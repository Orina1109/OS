#include <stdio.h>
#include <stdlib.h>

typedef struct list_node {
	struct list_node* next;
	struct list_node* prev;
	int value;
} list_node;

list_node** init_list()
{
	list_node** root = (list_node**)malloc(sizeof(list_node*));
	*root = NULL;
	return root;
}

void insert_first(list_node** list, int value)
{
	if (*list == NULL)
	{
		*list = (list_node*)malloc(sizeof(list_node));
		list_node* root = *list;
		root->next = NULL;
		root->prev = NULL;
		root->value = value;
		return;
	}
	
	list_node* node = (list_node*)malloc(sizeof(list_node));
	node->next = *list;
	node->prev = NULL;
	node->value = value;
	*list = node;
}

void insert_last(list_node** list, int value)
{
	list_node* node = (list_node*)malloc(sizeof(list_node));
	node->next = NULL;
	node->value = value;
	
	list_node* temp = *list;
	while(temp->next != NULL)
		temp = temp->next;
	temp->next = node;
	node->prev = temp;
}

int list_size(list_node** list)
{
	int size = 0;
	list_node* temp = *list;
	if (temp == NULL)
		return 0;
	
	while (temp->next != NULL)
	{
		temp = temp->next;
		size++;
	}
	return size + 1;
}


void insert(list_node** list, int index, int value)
{
	int size = list_size(list);
	if (index == 0)
	{
		insert_first(list, value);
		return;
	}
	if (index == size)
	{
		insert_last(list, value);
		return;
	}
	
	list_node* root = *list;
	int cur_ind = 0;
	while (root->next != NULL && cur_ind < index - 1)
	{
		root = root->next;
		cur_ind++;
	}
	
	list_node* node = (list_node*)malloc(sizeof(list_node));
	node->value = value;
	node->next = root->next;
	root->next = node;
	node->prev = root;
}

void delete_first(list_node** list)
{
	int size = list_size(list);
	if (size == 0)
		return;
	list_node* node = *list;
	*list = (*list)->next;
	(*list)->prev = NULL;
	free(node);
}

void delete_last(list_node** list)
{
	int size = list_size(list);
	if (size == 0)
		return;
	if (size == 1)
	{
		delete_first(list);
		return;
	}
	
	list_node* temp = *list;
	while(temp->next->next != NULL)
		temp = temp->next;
	free(temp->next);
	temp->next = NULL;
}

void delete(list_node** list, int index)
{
	int size = list_size(list);
	if (index == 0)
	{
		delete_first(list);
		return;
	}
	if (index == size - 1)
	{
		delete_last(list);
		return;
	}
	
	list_node* root = *list;
	int cur_ind = 0;
	while (root->next->next != NULL && cur_ind < index - 1)
	{
		root = root->next;
		cur_ind++;
	}
	
	list_node* node = root->next;
	root->next = root->next->next;
	root->next->prev = root;
	free(node);
}

void print_list(list_node** list)
{
	list_node* root = *list;
	if (list == NULL)
		return;
	do 
	{
		printf("%d ", root->value);
		root = root->next;
	} while(root != NULL);
	printf("\n");
}

int main()
{
	list_node** list = init_list();
	insert_first(list, 3);
	insert_first(list, 2);
	insert_first(list, 1);
	insert_first(list, 0);
	insert_last(list, 4);
	insert(list, 1, 10);
	insert(list, 5, 10);
	delete(list, 1);
	print_list(list);	
}