//
// Created by joao_vieira on 29/08/2021.
//

#ifndef UNTITLED2_deckOPERATORS_H
#define UNTITLED2_deckOPERATORS_H

#include <cstdlib>
#include <iostream>

//typedef for deck`s operators
typedef struct deck deck;
//typedef for card lists operators
typedef struct deck *serie;


void deckInitialize(deck *);

void cardsInitialize(serie);

int topDelete(deck *);

void endInsert(deck *, serie);

void cardPop(serie, int);

void printTop(deck *);


#endif //UNTITLED2_deckPERATORS_H
