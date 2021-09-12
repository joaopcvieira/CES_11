#include "list.h"

#include <assert.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

struct list {
    LIST *prox;
    unsigned int max, size;
    int num;
};

void list_create(LIST *list, unsigned int max) {

    list->max = max;
    list->size = 0;
    list->prox = NULL;

}

void list_destroy(LIST *list) {
    LIST *p;
    unsigned int i;
    do {
        for (i = 0, p = list; i < list->size - 1; i++, p = p->prox);
        free(p->prox);
        list->size--;
    } while (list->size > 0);
}

unsigned int list_max(LIST *list) { return list->max; }

unsigned int list_size(LIST *list) { return list->size; }

void list_print(LIST *list, unsigned int idx) {
    int value = list_value(list, idx);
    printf("%d\n", value);
}


void list_insert(LIST *list, int value, unsigned int k) {
    unsigned int i, j;
    LIST *p;
    if (k >= list->max || list->size == list->max || k < list->size)
        printf("ERRO!\n");
    else {
        // placing p in the last position to move the necessary values
        // one position ahead
        for (i = 1, p = list; i < list->size; i++, p = p->prox);
        if (list->size != 0) {
            p->prox = (LIST *) malloc(sizeof(LIST));
            p->prox->num = p->num;
        }

        j = list->size;
//        Function to move all numbers one position ahead
        LIST *temp;
//        setting temp in the k position
        for (i = 0, temp = list; i < k; i++, temp = temp->prox);

        while (j > k) {
            for (i = 1, p = temp; i < j && p->prox != NULL; i++, p = p->prox);
            p->prox->num = p->num;
            j--;

        }

        p = temp;
        p->num = value;

        list->size++;
    }
}

void list_delete(LIST *list, unsigned int k) {
    unsigned int i;
    LIST *p;
    if (list->size <= k)
        printf("ERRO!\n");
    else {

//    setting p in the k position
        for (i = 0, p = list; i < k; i++, p = p->prox);
//    moving all values one place back
        for (; p->prox != NULL; p = p->prox) {
            p->num = p->prox->num;
        }
        if (list->size != 1 ) {
//          setting p in the last - 1 position
            for (i = 0, p = list; i < list->size - 1 || p->prox != NULL; i++, p = p->prox);
            p->prox = NULL;
        }

        list->size--;
    }
}

int list_value(LIST *list, unsigned int idx) {
    unsigned int i;
    LIST *p = list;

    if (list->size <= idx) {
        printf("ERRO!\n");
        return -9999;
    } else {

//    setting p in the idx position
        for (i = 0; i < idx; i++, p = p->prox);

        return p->num;
    }
}

void list_change(LIST *list, int value, unsigned int idx) {
    unsigned int i;
    LIST *p = list;
    if (idx >= list->size)
        printf("ERRO!\n");
    else {
        for (i = 0; i < idx; i++, p = p->prox);
        p->num = value;
    }
}
