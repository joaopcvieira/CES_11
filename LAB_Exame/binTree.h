/*
 * Abstract Data Type Declarations -- BINTREE
 * author: ljr
 *
 */

#ifndef BINTREE_H
#define BINTREE_H

#include "atomSet.h"
#include "adt_stack.h"
#include "list.h"

// binary tree typedefs

typedef struct cell {
    atom_st elem;
    struct cell *parent, *lchild, *rchild; // pai, filho esquerdo e filho direito
} cell_st;

typedef cell_st *bintree_node;

/*
 * Binary Tree Functions
 */

bintree_node make_tree(atom_st*, int);
int eval_expression(bintree_node);
void print_parenthetical_expr(bintree_node);

// other bintree manipulation functions

#endif // BINTREE_H