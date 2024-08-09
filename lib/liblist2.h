
typedef struct _node {
    void *value;
    struct _node *next;
    struct _node *prev; 
} node_t;


typedef struct _list2 {
    size_t size;
    node_t *head;
    node_t *tail;
} list2_t;

list2_t* list2_create();

void list2_delete(list2_t **list);

void list2_push_front(list2_t *list, void *data);

void *list2_pop_front (list2_t *list);

void list2_push_back (list2_t *list, void *value);

void *list2_pop_back (list2_t *list);

node_t *list2_get_Nth (list2_t *list, size_t index);

node_t *list2_get_Nthq (list2_t *list, size_t index);

void list2_insert (list2_t *list, size_t index, void *value);

void *list2_delete_Nth (list2_t *list, size_t index);

void list2_print(list2_t *list, void (*fun) (void *));

list2_t *list2_from_array (void *arr, size_t n, size_t size);

void list2_print_int(void *value);