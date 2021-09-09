/* 
 * Abstract Data Type Declarations -- STACK
 * author: dloubach
 *
 */

#ifndef ADT_STACK_H
#define ADT_STACK_H

#include <stdbool.h>

/* ADT stack type declaration */
typedef struct node_st* stack_t;

/* ADT stack operators */

/* inicializa uma pilha vazia */
void adt_initStack(stack_t*);

/* adiciona um elemento no topo da pilha*/
void adt_pushStack(stack_t*, double);

/* remove um elemento do topo da pilha */
void adt_popStack(stack_t*);

/* retorna o elemento do topo da pilha sem remove-lo */
double adt_topStack(stack_t);

/* retorna <true> quando a pilha encontra-se vazia */
bool adt_isEmptyStack(stack_t);

/* esvazia a pilha */
void adt_emptyStack(stack_t*);

#endif