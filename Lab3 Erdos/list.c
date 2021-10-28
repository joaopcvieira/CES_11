//
// Created by joao_vieira on 27/10/2021.
//

#include "list.h"

#include <assert.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>


void list_create(LIST *list, int max) {
    list->size = 0;
    list->prox = NULL;
}

int list_size(LIST *list) { return list->size; }


void list_insert(LIST *list, POSITION value) {
    if (list->size == 0)
        list->size++;

    if (list->prox != NULL) {
        list_insert(list->prox, value);
        list->size++;
    } else {
        list->prox = (LIST *) malloc(sizeof(LIST));
        list->prox->prox = NULL;
        list->prox->element = value;
    }
}

void list_delete(LIST *list, int k) {
    unsigned int i;
    LIST *p;
    if (list->size <= k)
        printf("ERRO in list_delete!\n");
    else {

//    setting p in the k position
        for (i = 0, p = list; i < k; i++, p = p->prox);
//    moving all values one place back
        for (; p->prox != NULL; p = p->prox) {
            list->prox->element = p->prox->element;
        }
        if (list->size != 1) {
//          setting p in the last - 1 position
            for (i = 0, p = list; i < list->size - 1 || p->prox != NULL; i++, p = p->prox);
            p->prox = NULL;
        }

        list->size--;
    }
}

POSITION list_value(LIST *list, int idx) {
    int i;
    LIST *p = list;

//    setting p in the idx position
    for (i = 0; i < idx; i++, p = p->prox);
    return p->element;
}

void list_change(LIST *list, POSITION value, int idx) {
    unsigned int i;
    LIST *p = list;
    if (idx >= list->size)
        printf("ERRO!\n");
    else {
        for (i = 0; i < idx; i++, p = p->prox);
        list->prox->element = value;
    }
}



POSITION list_last(LIST *list) {
    if (list->prox == NULL) {
        return list->element;
    } else {
        return list_last(list->prox);
    }
}

void list_PopLast(LIST *list) {
    LIST *p = list;
    int m;
    if (p->prox != NULL) {
        for (m = 1; p->prox->prox != NULL; m++, p = p->prox);
    }
    free(p->prox);
    p->prox = NULL;
    list->size--;
}