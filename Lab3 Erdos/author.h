//
// Created by joaop on 23/10/2021.
//

#ifndef LAB3_ERDOSNUMBER_AUTHOR_H
#define LAB3_ERDOSNUMBER_AUTHOR_H

#include <stdio.h>
#include <string.h>

#define MAX_AUTHORS 100
#define MAX_EXPR 1000

typedef char NAME[20];
typedef struct {
    NAME name; //author's name
    int erdosNum; // author's Erdos number
    int paper;  //paper he's inserted in
} object;

object author[MAX_AUTHORS];
char expr[MAX_EXPR];

void readAuthors(int);


#endif //LAB3_ERDOSNUMBER_AUTHOR_H
