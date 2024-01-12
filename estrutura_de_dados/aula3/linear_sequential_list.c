#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 50

typedef int key_type;

typedef struct
{
    key_type key;
} _register;

typedef struct
{
    _register data[MAX];
    int size;
} list;

void create_list(list *l)
{
    l->size = 0;
}

int size_list(list *l)
{
    return l->size;
}

void print_list(list *l)
{
    printf("List: [ ");
    for (int i = 0; i < l->size; i++)
        printf("%i ", l->data[i].key);
    printf("]\n");
}

int search_elem_list(list *l, key_type key)
{
    for (int i = 0; i < l->size; i++)
        if (key == l->data[i].key)
            return i;
    return -1;
}

// this will need the data array to have [MAX + 1] elements allocated
int sentinel_search(list *l, key_type key)
{
    int i = 0;
    l->data[l->size].key = key; // placing the sentinel element
    while (l->data[i].key != key)
        i++;
    if (i == l->size)
        return -1;
    else
        return i;
}

bool insert_elem_list(list *l, _register reg, int i)
{
    if (i < 0 || i > l->size || l->size == MAX)
        return false;
    for (int j = l->size - 1; j > i; j--)
        l->data[j] = l->data[j - 1];
    l->data[i] = reg;
    l->size++;
    return true;
}

bool delete_elem_list(list *l, key_type key)
{
    int pos = search_elem_list(l, key);
    if (pos == -1)
        return false;
    for (int j = pos; j < l->size - 1; j++)
        l->data[j] = l->data[j + 1];
    l->size--;
    return true;
}

void restart_list(list *l)
{
    l->size = 0;
}

int main()
{
    list l;

    create_list(&l);

    _register reg;
    reg.key = 10;
    insert_elem_list(&l, reg, 0);

    reg.key = 20;
    insert_elem_list(&l, reg, 1);

    reg.key = 30;
    insert_elem_list(&l, reg, 2);

    print_list(&l);
    printf("Size of list: %d\n", size_list(&l));
    printf("Index of 30: %d\n", search_elem_list(&l, 30));
    delete_elem_list(&l, 30);
    print_list(&l);
    printf("Size of list: %d\n", size_list(&l));
    restart_list(&l);
    printf("Size of list: %d\n", size_list(&l));

    return 0;
}
