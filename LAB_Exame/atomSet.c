/* 
 * Abstract Data Type Declarations -- ATOMSET
 * author: ljr
 *
 */
#include "atomSet.h"

// AtomSet functions implementation

void make_atoms() {

    Zero out the number of atoms found;
    Place the cursor on initial position; // i = 0
    Capture the first character non-white;

    while this character != '\0' {
        insert new atom in parenthetical
        
        switch (according to the value of the char)
            case "if digit" 
                collect all digits
                atom type if NUMBER
                the attribute is the numeric
                value of the string collected
                by all sequence digits

            case "if "+" or "*""
                atom type if OP
                attribute is the character itself

            case "if "(" or ")""
                atom type if OPAR or CPAR respectively
                attribute is not necessary

            case "any other character"
                atom type is INVAL
                attribute is the character itself
        } 

        update increasing natoms
        next non-white-character
    } 

}

void print_atoms(atom_st* atomsVector, int atomsNumber) {
    printf("\ntype      | attribute\n----------------------\n");
    for(int j = 0; j < atomsNumber - 1; ++j)
    {
        if(atomsVector[j].type == NUMBER)
            printf("NUMBER    | %d\n", atomsVector[j].attribute.value);
        else if(atomsVector[j].type == OP)
            printf("OP        | %c\n", atomsVector[j].attribute.op);
        else if(atomsVector[j].type == OPAR)
            printf("OPAR      |\n");
        else if(atomsVector[j].type == CPAR)
            printf("CPAR      |\n");
        else if(atomsVector[j].type == INVAL)
            printf("INVAL     | %c\n", atomsVector[j].attribute.character);
    }
}

char get_non_blank() {
    while(isspace(expr[i]) || (iscntrl(expr[i]) && expr[i] != '\0'))
        ++i;
    return expr[i];
}

char get_next() {
    ++i;
    return expr[i];
}

void init_expr() {
    i = 0;
}