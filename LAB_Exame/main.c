/* 
 * LAB Parenthetical Expression Evaluation
 * main code
 */

#include "atomSet.h"
#include "adt_stack.h"
#include "list.h"
#include "binTree.h"
#include "PolishExpr.h"

int main() {

    printf("Expression: ");
    fgets(expr, MAX_EXPR, stdin);

    make_atoms();
    printf("\nAtoms found in expression: \n");
    print_atoms(parenthetical, natoms);

    // print the polish expression
    printf("\nPolish expression:  ");


    LIST polishVector = polishTranslate(parenthetical);
    int polishSize = polishVector.size;

    bintree_node tree = make_tree(&polishVector, polishSize);
    printf("\nParenthetical expression from binary tree: ");
    print_parenthetical_expr(tree);

    printf("\n\nThe result of evalutation is: %d\n", eval_expression(tree));

    return 0;
}