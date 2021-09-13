/* 
 * Abstract Data Type Implementations -- STACK
 * author: dloubach
 *
 */

#include <stdlib.h>
#include "adt_stack.h"



/* ADT stack operators */

/* inicializa uma pilha vazia */
void adt_initStack(stack_t *stackArg) {
    (*stackArg) = (stack_t) malloc(sizeof(struct node_st));
    (*stackArg)->element = 0;
    (*stackArg)->next = NULL;

}

/* adiciona um elemento no topo da pilha*/
void adt_pushStack(stack_t *stackArg, ELEMENT_USED elementArg) {
    stack_t p = *stackArg;
    *stackArg = (stack_t) malloc(sizeof(struct node_st));
    (*stackArg)->element = elementArg;
    (*stackArg)->next = p;
}

/* remove um elemento do topo da pilha */
void adt_popStack(stack_t *stackArg) {

    stack_t p;
    if (*stackArg != NULL) {
        p = *stackArg;
        *stackArg = (*stackArg)->next;
        free(p);
    } else
        printf("Erro!\n");
}


/* retorna o elemento do topo da pilha sem remove-lo */
ELEMENT_USED adt_topStack(stack_t stackArg) {
    if (stackArg != NULL)
        return stackArg->element;
    else
        printf("ERRO! Topo vazio");
    return 0;

}

/* retorna <true> quando a pilha encontra-se vazia */
bool adt_isEmptyStack(stack_t stackArg) {
    if (stackArg->next == NULL)
        return true;
    else
        return false;
}

/* esvazia a pilha */
void adt_emptyStack(stack_t *stackArg) {
    stack_t p;
    while (!adt_isEmptyStack(*stackArg)) {
        for (p = *stackArg; p->next->next != NULL; p = p->next);
        free(p->next);
        p->next = NULL;
    }
}
