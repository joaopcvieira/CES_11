/* 
 * Abstract Data Type Implementations -- STACK
 * author: dloubach
 *
 */

#include <stdlib.h>
//#include <cstdio>
#include "adt_stack.h"

/* ADT stack node implementation */
struct node_st {
    double element;
    struct node_st *next;
};

/* ADT stack operators */

/* inicializa uma pilha vazia */
void adt_initStack(stack_t *stackArg) {
    (*stackArg) = (stack_t) malloc(sizeof(struct node_st));
    (*stackArg)->element = 0;
    (*stackArg)->next = NULL;

}

/* adiciona um elemento no topo da pilha*/
void adt_pushStack(stack_t *stackArg, double elementArg) {
    stack_t p = *stackArg;
    for (; p->next != NULL; p = p->next);
    p->next = (stack_t) malloc(sizeof(struct node_st));
    p->next->element = elementArg;
}

/* remove um elemento do topo da pilha */
void adt_popStack(stack_t *stackArg) {
    stack_t p = *stackArg;
    if (p->next != NULL) {
        if (!adt_isEmptyStack(*stackArg)) {
            for (; p->next->next != NULL; p = p->next);
            free(p->next);
            p->next = NULL;
        }
    }


}

/* retorna o elemento do topo da pilha sem remove-lo */
double adt_topStack(stack_t stackArg) {
    for (; stackArg->next != NULL; stackArg = stackArg->next);
    return stackArg->element;

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
