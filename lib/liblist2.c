#include <stdlib.h>
#include <stdio.h>
#include "liblist2.h" 

list2_t* list2_create() {
    list2_t *tmp = (list2_t*) malloc(sizeof(list2_t));
    tmp->size = 0;
    tmp->head = tmp->tail = NULL;

    return tmp;
}

void list2_delete(list2_t **list) {
    node_t *tmp = (*list)->head;
    node_t *next = NULL;
    while (tmp) {
        next = tmp->next;
        free(tmp);
        tmp = next;
    }
    free(*list);
    (*list) = NULL;
}

void list2_push_front(list2_t *list, void *data) {
    node_t *tmp = (node_t*) malloc(sizeof(node_t));
    if (tmp == NULL) {
        exit(1);
    }
    tmp->value = data;
    tmp->next = list->head;
    tmp->prev = NULL;
    if (list->head) {
        list->head->prev = tmp;
    }
    list->head = tmp;
 
    if (list->tail == NULL) {
        list->tail = tmp;
    }
    list->size++;
}

void *list2_pop_front (list2_t *list)
{
	node_t *prev;
	void *tmp;

	if (list->head == NULL)
		exit (2);

	prev = list->head;
	list->head = list->head->next;

	if (list->head)
		list->head->prev = NULL;

	if (prev == list->tail)
		list->tail = NULL;

	tmp = prev->value;
	free (prev);

	list->size--;
	return tmp;
}

void list2_push_back (list2_t *list, void *value)
{
	node_t *tmp = (node_t *) malloc (sizeof (node_t));

	if (tmp == NULL)
		exit (3);

	tmp->value = value;
	tmp->next = NULL;
	tmp->prev = list->tail;

	if (list->tail)
		list->tail->next = tmp;

	list->tail = tmp;

	if (list->head == NULL)
		list->head = tmp;

	list->size++;
}

void *list2_pop_back (list2_t *list)
{
	node_t *next;
	void *tmp;

	if (list->tail == NULL)
		exit (4);

	next = list->tail;
	list->tail = list->tail->prev;

	if (list->tail)
		list->tail->next = NULL;

	if (next == list->head)
		list->head = NULL;

	tmp = next->value;
	free (next);

	list->size--;
	return tmp;
}


node_t *list2_get_Nth (list2_t *list, size_t index)
{
	node_t *tmp = list->head;
	size_t i = 0;

	while (tmp && i < index)
	{
		tmp = tmp->next;
		i++;
	}

	return tmp;
}

node_t *list2_get_Nthq (list2_t *list, size_t index)
{
	node_t *tmp = NULL;
	size_t i;

	if (index < list->size/2)
	{
		i = 0;
		tmp = list->head;

		while (tmp && i < index)
		{
			tmp = tmp->next;
			i++;
		}
	}
	else
	{
		i = list->size - 1;
		tmp = list->tail;

		while (tmp && i > index)
		{
			tmp = tmp->prev;
			i--;
		}
	}

	return tmp;
}

void list2_insert (list2_t *list, size_t index, void *value)
{
	node_t *elm = NULL;
	node_t *ins = NULL;
	elm = list2_get_Nth (list, index);

	if (elm == NULL)
		exit (5);

	ins = (node_t *) malloc (sizeof (node_t));
	ins->value = value;
	ins->prev = elm;
	ins->next = elm->next;

	if (elm->next)
		elm->next->prev = ins;

	elm->next = ins;

	if (!elm->prev)
		list->head = elm;

	if (!elm->next)
		list->tail = elm;

	list->size++;
}

void *list2_delete_Nth (list2_t *list, size_t index)
{
	node_t *elm = NULL;
	void *tmp = NULL;
	elm = list2_get_Nth (list, index);

	if (elm == NULL)
		exit (5);

	if (elm->prev)
		elm->prev->next = elm->next;

	if (elm->next)
		elm->next->prev = elm->prev;

	tmp = elm->value;

	if (!elm->prev)
		list->head = elm->next;

	if (!elm->next)
		list->tail = elm->prev;

	free (elm);

	list->size--;

	return tmp;
}


void list2_print(list2_t *list, void (*fun) (void *))
{
	node_t *tmp = list->head;

	while (tmp)
	{
		fun (tmp->value);
		tmp = tmp->next;
	}

	printf ("\n");
}


void list2_print_int (void *value)
{
	printf ("%d ", * ((int *) value));
}


list2_t *list2_from_array (void *arr, size_t n, size_t size)
{
	list2_t *tmp = NULL;
	size_t i = 0;

	if (arr == NULL)
		exit (7);

	tmp = list2_create();

	while (i < n)
	{
		list2_push_back (tmp, ((char *)arr + i*size));
		i++;
	}

	return tmp;
}
