/*
 * Abstract Data Type Declarations -- BINTREE
 * author: ljr
 *
 */
#include "binTree.h"

// create the tree
bintree_node make_tree(LIST *vector, int size) {
    bintree_node p = bt;

    bt = auxMake_tree(&p, vector, vector->size);


    p = bt;
    return bt;
}

int eval_expression(bintree_node bt) {
    if (bt->elem.type == NUMBER)
        return bt->elem.attribute.value;
    else if (bt->elem.attribute.op == '+')
        return eval_expression(bt->rchild) + eval_expression(bt->lchild);
    else if (bt->elem.attribute.op == '*')
        return eval_expression(bt->rchild) * eval_expression(bt->lchild);
    return -1;
}

void print_parenthetical_expr(bintree_node noh) {
    if (noh->lchild == NULL && noh->rchild == NULL) {
        printf("%d", noh->elem.attribute.value);
    } else {
        printf("(");
        print_parenthetical_expr(noh->lchild);
        printf(" %c ", noh->elem.attribute.op);
        print_parenthetical_expr(noh->rchild);
        printf(")");
    }
}

bool isInt(char *strArg) {
    if (strArg[0] - '0' >= 0 && strArg[0] - '0' <= 9)
        return 1;
    else
        return 0;
}

bintree_node auxMake_tree(bintree_node *p, LIST *vectorArg, int size) {
    if (size > 0) {
        if (isInt(list_last(vectorArg))) {
            (*p) = (bintree_node) malloc(sizeof(cell_st));
            (*p)->elem.type = NUMBER;
            (*p)->elem.attribute.value = atoi(list_last(vectorArg));
            list_PopLast(vectorArg);

            return (*p);

        } else {
            (*p) = (bintree_node) malloc(sizeof(cell_st));

            (*p)->elem.type = OP;
            (*p)->elem.attribute.op = list_last(vectorArg)[0];
            list_PopLast(vectorArg);

            //recursive use to fill the tree
            (*p)->rchild = (bintree_node) malloc(sizeof(cell_st));
            (*p)->rchild->parent = (*p);
            (*p)->rchild->lchild = NULL;
            (*p)->rchild->rchild = NULL;

            (*p)->rchild = auxMake_tree(&(*p)->lchild, vectorArg, vectorArg->size);

            //recursive use to fill the tree
            (*p)->lchild = (bintree_node) malloc(sizeof(cell_st));
            (*p)->lchild->parent = (*p);
            (*p)->lchild->lchild = NULL;
            (*p)->lchild->rchild = NULL;

            (*p)->lchild = auxMake_tree(&(*p)->lchild, vectorArg, vectorArg->size);


        }
    }
    return *p;
}
