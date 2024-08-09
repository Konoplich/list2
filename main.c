#include <stdio.h>
#include <stdlib.h>
#include "liblist2.h"
 
int main () {
	list2_t *list = list2_create();
    int a, b, c, d, e, f, g, h;
     
    a = 10;
    b = 20;
    c = 30;
    d = 40;
    e = 50;
    f = 60;
    g = 70;
    h = 80;
    list2_push_front(list, &a);
    list2_push_front(list, &b);
    list2_push_front(list, &c);
    list2_push_back(list, &d);
    list2_push_back(list, &e);
    list2_push_back(list, &f);
    list2_print(list, list2_print_int);
    printf("length %d\n", list->size);
    printf("nth 2 %d\n", *((int*)(list2_get_Nthq(list, 2))->value));
    printf("nth 5 %d\n", *((int*)(list2_get_Nthq(list, 5))->value));
    printf("list2_pop_front %d\n", *((int*)list2_pop_front(list)));
    printf("list2_pop_front %d\n", *((int*)list2_pop_front(list)));
    printf("head %d\n", *((int*)(list->head->value)));
    printf("tail %d\n", *((int*)(list->tail->value)));
    printf("list2_pop_back %d\n", *((int*)list2_pop_back(list)));
    printf("list2_pop_back %d\n", *((int*)list2_pop_back(list)));
    printf("length %d\n", list->size);
    printf("list2_print\n");
    list2_print(list, list2_print_int);
    printf("list2_insert %d, %d\n",1,g);
    list2_insert(list, 1, &g);
    printf("list2_print\n");
    list2_print(list, list2_print_int);
    printf("list2_delete %d\n",0);
    list2_delete_Nth(list, 0);
    printf("list2_print\n");
    list2_print(list, list2_print_int);
    list2_delete(&list);
     
    getchar();
}
