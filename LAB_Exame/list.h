#ifndef LIST_H
#define LIST_H

#include "atomSet.h"
#define MaxStrSize 10

typedef struct list LIST; // não altere esta linha
struct list {
    LIST *prox;
    unsigned int max, size;
    char element[MaxStrSize];
};

/** Criação e destruição do TAD **/

// Criar o TAD LIST
//
// max - máximo de elementos que a lista deve suportar
void list_create(LIST *list, unsigned int max);   // não altere esta linha

// Destroi o TAD LIST
//
// list - ponteiro para o TAD
void list_destroy(LIST *list); // não altere esta linha


/** Informações sobre o TAD **/

// Máximo de elementos suportado pelo TAD
unsigned int list_max(LIST *list);   // não altere esta linha

// Quantidade de elementos na lista
unsigned int list_size(LIST *list);  // não altere esta linha


/** Operações do TAD **/
void list_insert(LIST *list, char *value);  // não altere esta linha
void list_delete(LIST *list, unsigned int idx);  // não altere esta linha
char *list_value(LIST *list, unsigned int idx);  // não altere esta linha
void list_change(LIST *list, char *value, unsigned int idx);  // não altere esta linha
void list_print(LIST *list);
char *list_last(LIST *list);
void list_PopLast(LIST *list);


// acrescente outras declarações, caso desejar

#endif // LIST_H