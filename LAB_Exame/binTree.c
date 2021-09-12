/*
 * Abstract Data Type Declarations -- BINTREE
 * author: ljr
 *
 */
#include "binTree.h"

// create the tree
bintree_node make_tree(atom_st* vector, int size) {
    // YOUR CODE HERE
}

int eval_expression(bintree_node bt) {
    if(bt->elem.type == NUMBER)
        return bt->elem.attribute.value;
    else if(bt->elem.attribute.op == '+')
        return eval_expression(bt->rchild) + eval_expression(bt->lchild);
    else if(bt->elem.attribute.op == '*')
        return eval_expression(bt->rchild) * eval_expression(bt->lchild);
    return -1;
}

void print_parenthetical_expr(bintree_node noh) {
    if(noh->lchild == NULL && noh->rchild == NULL) {
        printf("%d", noh->elem.attribute.value);
    } else {
        printf("(");
        print_parenthetical_expr(noh->lchild);
        printf(" %c ", noh->elem.attribute.op);
        print_parenthetical_expr(noh->rchild);
        printf(")");
    }
}
