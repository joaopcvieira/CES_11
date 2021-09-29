//
// Created by joao_vieira on 29/08/2021.
//

#include "DeckOperators.h"

// Define struct deck
struct deck {
    int card;
    deck *last, *nex;
    unsigned int size;
};

//    Initialize deck for further operations
void deckInitialize(deck *player) {
    player->last = player;
    player->size = 0;
    player->nex = (deck *) malloc(sizeof(deck));

}

//    Initialize deck for further operations
void cardsInitialize(serie listCards) {

    listCards->last = listCards;
    listCards->card = -1;
    listCards->size = 0;
    listCards->nex = (serie) malloc(sizeof(deck));

}


//    Function to return the top value and
//    delete it
int topDelete(deck *player) {
    int returnCard = player->card;
    if (player->size != 0) {
        player->nex = player->nex->nex;
        player->size--;
        return returnCard;
    } else {
        std::cout << "ERRO! Size 0" << std::endl;
        return -9999;
    }

}


// Insert cards in player`s deck
void endInsert(deck *player, serie cards) {
    if (player->size == 0)
        player = cards;
    else {
        player->last->nex = (deck *) malloc(sizeof(deck));

        player->last = player->last->nex;
        player->last = cards;
        player->last = cards->last;

        player->size += cards->size;
    }
    deck *p;
//    for (unsigned int i = 1; i < cards->size; i++) {
//        p = cards;
//        cards = cards->nex;
//        free(p);
//    }


}


// Add a card to cards deck
void cardPop(serie listCards, int card) {
    if (listCards->size > 1) {

        /* TODO How to put this line in C++ ????? */
        listCards->last->nex = (deck *) malloc(sizeof(deck));

        listCards->last = listCards->last->nex;
        listCards->last->card = card;
    } else if (listCards->size == 1) {
        listCards->last->card = card;
    } else if (listCards->size == 0) {
        listCards->card = card;
        listCards->last = listCards->nex;
    }
    listCards->size++;

}

void printTop(deck *player) {
    std::string naipe;
    char number;
    int temp = player->card;

//    Defining patter for cards
//    Using Truco`s "manilhas" priority of "naipes"
    switch (temp % 4) {
        case 0:
            naipe = "Paus";
            break;
        case 1:
            naipe = "Copas";
            break;
        case 2:
            naipe = "Espadas";
            break;
        case 3:
            naipe = "Ouros";
            break;
    }
    switch (temp / 4) {
        case 0:
            number = 'A';
            break;
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
            number = (char) (temp / 4);
            break;
        case 11:
            number = 'J';
            break;
        case 12:
            number = 'Q';
            break;
        case 13:
            number = 'K';
            break;
        default:
            number = '!';
            break;

    }

    std::cout << number << " de " << naipe << std::endl;
}


