//
// Created by joao_vieira on 29/09/2021.
//

#ifndef WARGAMESIMULATOR_ADTQUEUE_H
#define WARGAMESIMULATOR_ADTQUEUE_H

#include <cstdlib>
#include <iostream>

//typedef for queue`s operators
typedef struct queue queue;

// Define struct queue
typedef struct node node;
struct node {
    int elem;
    node *prox;
};
struct queue {
    node *fr, *tr;
};


//typedef for card lists operators
typedef struct queue *serie;


void queueInitialize(queue *);

void cardsInitialize(node**);

void deleteCards (node**);

void randomInicializeCards(node*);

void divideCards(node*, node**, node**);

int topDelete(queue *);

void endInsert(queue *, node*);

void cardPop(node*, int);

void printTop(queue *);

bool isEmpty(queue*);



#endif //WARGAMESIMULATOR_ADTQUEUE_H
