/* 
 * Abstract Data Type Implementations -- STACK
 * author: dloubach
 *
 */

#include <stdlib.h>
#include "adt_stack.h"

/* ADT stack node implementation */
struct node_st{
  double element;
  struct node_st* next;
};

/* ADT stack operators */

/* inicializa uma pilha vazia */
void adt_initStack(stack_t* stackArg) {
  // SEU CODIGO AQUI  
}

/* adiciona um elemento no topo da pilha*/
void adt_pushStack(stack_t* stackArg, double elementArg) {
  // SEU CODIGO AQUI
}

/* remove um elemento do topo da pilha */
void adt_popStack(stack_t* stackArg) {
  // SEU CODIGO AQUI
}

/* retorna o elemento do topo da pilha sem remove-lo */
double adt_topStack(stack_t stackArg) {
  // SEU CODIGO AQUI
}

/* retorna <true> quando a pilha encontra-se vazia */
bool adt_isEmptyStack(stack_t stackArg) {
  // SEU CODIGO AQUI
}

/* esvazia a pilha */
void adt_emptyStack(stack_t *stackArg) {
// SEU CODIGO AQUI
}