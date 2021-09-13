#include "list.h"

#include <assert.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

//struct list {
//    LIST *prox;
//    unsigned int max, size;
//    attribute_ut element;
//};

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


void list_insert(LIST *list, char *value) {
    if (list->size == 0)
        list->size++;

    if (list->prox != NULL) {
        list_insert(list->prox, value);
        list->size++;
    } else {
        list->prox = (LIST *) malloc(sizeof(LIST));
        list->prox->prox = NULL;
        for (int e = 0; value[e - 1] != '\0' && e < MaxStrSize; e++)
            list->prox->element[e] = value[e];

    }
/*

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
            p->prox->element = p->element;
        }

        j = list->size;
//        Function to move all elementbers one position ahead
        LIST *temp;
//        setting temp in the k position
        for (i = 0, temp = list; i < k; i++, temp = temp->prox);

        while (j > k) {
            for (i = 1, p = temp; i < j && p->prox != NULL; i++, p = p->prox);
            p->prox->element = p->element;
            j--;

        }

        p = temp;
        p->element = value;

        list->size++;
    }
    */
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
            for (int e = 0; p->prox->element[e - 1] != '\0' && e < MaxStrSize; e++)
                list->prox->element[e] = p->prox->element[e];
//            p->prox->element
        }
        if (list->size != 1) {
//          setting p in the last - 1 position
            for (i = 0, p = list; i < list->size - 1 || p->prox != NULL; i++, p = p->prox);
            p->prox = NULL;
        }

        list->size--;
    }
}

char *list_value(LIST *list, unsigned int idx) {
    unsigned int i;
    LIST *p = list;

//    setting p in the idx position
    for (i = 0; i < idx; i++, p = p->prox);

    return p->element;

}

void list_change(LIST *list, char *value, unsigned int idx) {
    unsigned int i;
    LIST *p = list;
    if (idx >= list->size)
        printf("ERRO!\n");
    else {
        for (i = 0; i < idx; i++, p = p->prox);
        for (int e = 0; value[e - 1] != '\0' && e < MaxStrSize; e++)
            list->prox->element[e] = value[e];
    }
}

void list_print(LIST *list) {
    if (list->prox == NULL) {
        printf("ERRO!");
    } else {
        LIST *p = list->prox;
        for (; p != NULL; p = p->prox) {
            for (int m = 0; !iscntrl(p->element[m]) && p->element[m] != ' '; m++) {
                printf("%c", p->element[m]);
            }
            printf(" ");
        }
    }
}

char *list_last(LIST *list) {
    if(list->prox == NULL){
        return list->element;
    } else {
        return list_last(list->prox);
    }
//    LIST *p = &list;
//    int m;
//    for (m = 0; m < list.size && p->prox != NULL; m++, p = p->prox);
//    return p->element;
}

void list_PopLast(LIST *list) {
    LIST *p = list;
//    char temp[10];
    int m;
    if (p->prox != NULL) {
        for (m = 1;p->prox->prox != NULL; m++, p = p->prox);
    }
    free (p->prox);
    p->prox = NULL;
    list->size--;
//    return p->element;
}
