/*
 * Abstract Data Type Declarations -- ATOMSET
 * author: ljr
 *
 */
#include "atomSet.h"

// AtomSet functions implementation

void make_atoms() {

    natoms = 0;
    init_expr();
    c = get_non_blank();
    char temp[10];
    int l = 0 , k;

    while (c != '\0') {
//        insert new atom in parenthetical
        i++;
        parenthetical[l].attribute.value = 0;

        switch (c) {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
//            collect all digits
                temp[0] = c;
                for (k = 1; isdigit(temp[k - 1]); temp[k++] = get_next());
                temp[k - 1] = '\0';
                i--;

//        atom type if NUMBER the attribute is the numeric
//        value of the string collected by all sequence digit
                parenthetical[l].type = NUMBER;
                parenthetical[l].attribute.value = strtol(temp,  (char **) NULL, 10 );
                break;

            case '+':
            case '*':
//            atom type if OP
//            attribute is the character itself
                parenthetical[l].type = OP;
                parenthetical[l].attribute.op = c;
                break;


//        atom type if OPAR or CPAR respectively; attribute is not necessary
            case '(':
                parenthetical[l].type = OPAR;
                break;
            case ')':
                parenthetical[l].type = CPAR;
                break;
//
            default:
//            atom type is INVAL, attribute is the character itself
                parenthetical[l].type = INVAL;
                parenthetical[l].attribute.character = c;


                break;

        }

//    update increasing natoms
        natoms++; //TODO 1: conferir se eh so isso mesmo
        l++;
//    next non-white-character
        c = get_non_blank();
    }

}

void print_atoms(atom_st *atomsVector, int atomsNumber) {
//    printf("\nnumber of atoms = %d", natoms);

    printf("\ntype      | attribute\n----------------------\n");
    for (int j = 0; j < atomsNumber /* - 1 */; ++j) {
        if (atomsVector[j].type == NUMBER)
            printf("NUMBER    | %d\n", atomsVector[j].attribute.value);
        else if (atomsVector[j].type == OP)
            printf("OP        | %c\n", atomsVector[j].attribute.op);
        else if (atomsVector[j].type == OPAR)
            printf("OPAR      |\n");
        else if (atomsVector[j].type == CPAR)
            printf("CPAR      |\n");
        else if (atomsVector[j].type == INVAL)
            printf("INVAL     | %c\n", atomsVector[j].attribute.character);
    }
}

char get_non_blank() {
    while (isspace(expr[i]) || (iscntrl(expr[i]) && expr[i] != '\0'))
        ++i;
    return expr[i];
}

char get_next() {
//    ++i;
    return expr[i++];
}

void init_expr() {
    i = 0;
}