//
// Created by joao_vieira on 12/09/2021.
//

#include "PolishExpr.h"

LIST polishTranslate(atom_st *atomArg) {
    LIST returnList;
    list_create(&returnList, MAX_ATOMS);

    stack_t tempStack;
    adt_initStack(&tempStack);
    char tempStr[10];

    for (int k = 0; k < natoms; k++) {
        switch (atomArg[k].type) {
            case NUMBER:
                sprintf(tempStr, "%d", atomArg[k].attribute.value); //TODO 2 search a double to str function
                list_insert(&returnList,
                            tempStr);

                break;
            case OP:
                adt_pushStack(&tempStack,
                              atomArg[k].attribute.op);
                break;
            case CPAR:
                tempStr[0] = adt_topStack(tempStack);
                tempStr[1] = '\0';
                list_insert(&returnList,
                            tempStr);
                adt_popStack(&tempStack);
                break;
            case OPAR:
            case INVAL:
                break;

        }
    }

    list_print(&returnList);
    return returnList;
}

