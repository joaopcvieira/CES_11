#include <iostream>
#include "DeckOperators.h"
#include "GameMode.h"

//typedef for deck`s operators
typedef struct deck deck;
//typedef for card lists operators
typedef struct deck *serie;
struct deck {
    int card;
    deck *last, *nex;
    unsigned int size;
};

int main() {

    deck player1, player2, tempCard;
    deck *P1 = &player1, *P2 = &player2;
    serie cards = &tempCard;
    deckInitialize(P1);
    deckInitialize(P2);



    cardsInitialize(cards);

    for (unsigned int i = 1; i <= 52; i++) {
        cardPop(cards, i);
    }
    endInsert(&player1, cards);
    std::cout << player1.card;
    for (unsigned int i = 1; i <= 52; i++) {
        printTop(&player1);
        topDelete(&player1);
    }

    return 0;
}
