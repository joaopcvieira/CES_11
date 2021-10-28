//
// Created by joao_vieira on 27/10/2021.
//

#ifndef LAB3_ERDOS_LIST_H
#define LAB3_ERDOS_LIST_H


#include "author.h"


typedef struct list LIST;
typedef struct position POSITION;

struct position {
    int pos;
    NAME name;
};

struct list {
    LIST *prox;
    int size;
    POSITION element;
};

/** Criação do TAD **/

// Criar o TAD LIST
void list_create(LIST *list, int max);

/** Informações sobre o TAD **/
// Quantidade de elementos na lista
int list_size(LIST *list);

/** Operações do TAD **/
void list_insert(LIST *list, POSITION value);  // não altere esta linha
void list_delete(LIST *list, int idx);  // não altere esta linha
POSITION list_value(LIST *list, int idx);  // não altere esta linha
void list_change(LIST *list, POSITION value, int idx);  // não altere esta linha
POSITION list_last(LIST *list);
void list_PopLast(LIST *list);



#endif //LAB3_ERDOS_LIST_H
