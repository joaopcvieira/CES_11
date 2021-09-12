/*
 * Abstract Data Type Declarations -- ATOMSET
 * author: ljr
 *
 */

#ifndef ATOMSET_H
#define ATOMSET_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> // check characters

#define MAX_ATOMS 100
#define MAX_EXPR 1000

// type_et declaration based on enum
typedef enum {NUMBER, OP, OPAR, CPAR, INVAL} type_et;

//attribute_ut declaration based on union
typedef union {
    int value;
    char op;
    char character;
} attribute_ut;

// atom_st struct declaration
typedef struct {
    type_et type;
    attribute_ut attribute;
} atom_st;

// atoms vector to store expression atoms
atom_st parenthetical[MAX_ATOMS];

// character vector to store the expression
typedef char expression_t[MAX_EXPR];
expression_t expr;

// number of atoms in parenthetical and expr position
int natoms, i;

// store a single character from expr
char c;

/*
 * Atom Functions
 */

// find all atoms from expr and store them in parenthetical
void make_atoms(void);

// print all content of all atoms from a vetor of a atoms
void print_atoms(atom_st*, int);

// find the next non-white character from expr
char get_non_blank(void);

// return the next character from expr
char get_next(void);

// position the cursor i to first character from expr
void init_expr(void);

#endif