/* 
 * Abstract Data Type Declarations -- STACK
 * author: dloubach
 *
 */

#ifndef ADT_STACK_H
#define ADT_STACK_H

typedef char ELEMENT_USED;
#include <stdbool.h>
#include "atomSet.h"

/* ADT stack type declaration */
typedef struct node_st* stack_t;
struct node_st {
    ELEMENT_USED element;
    struct node_st *next;
};

/* ADT stack operators */

/* inicializa uma pilha vazia */
void adt_initStack(stack_t*);

/* adiciona um elemento no topo da pilha*/
void adt_pushStack(stack_t*, ELEMENT_USED);

/* remove um elemento do topo da pilha */
void adt_popStack(stack_t*);

/* retorna o elemento do topo da pilha sem remove-lo */
ELEMENT_USED adt_topStack(stack_t);

/* retorna <true> quando a pilha encontra-se vazia */
bool adt_isEmptyStack(stack_t);

/* esvazia a pilha */
void adt_emptyStack(stack_t*);

#endif







