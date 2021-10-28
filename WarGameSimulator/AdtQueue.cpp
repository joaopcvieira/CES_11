//
// Created by joao_vieira on 29/09/2021.
//

#include "AdtQueue.h"


//    Initialize queue for further operations
void queueInitialize(queue *player) {
    player->fr = new node;
    player->tr = player->fr;
    player->fr->prox = nullptr;

}

//    Initialize queue for further operations
void cardsInitialize(node **listCards) {
    *listCards = new node;
    (*listCards)->prox = nullptr;
}

void deleteCards(node **list) {
    node *aux = (*list)->prox;
    while ((*list)->prox != nullptr) {
        for (aux = (*list)->prox; aux->prox->prox != nullptr and aux->prox != nullptr; aux = aux->prox);
        free(aux->prox);
    }
}


//    Function to return the top value and
//    delete it
int topDelete(queue *player) {
    node *temp = player->fr->prox;
    if (temp == nullptr)
        return -1;
    int returnValue = temp->elem;

    if (player->fr->prox->prox != nullptr)
        player->fr->prox = player->fr->prox->prox;
    else {
        player->fr->prox = nullptr;
        player->fr = player->tr;
    }

    delete temp;

    return returnValue;
}


// Insert cards in player`s queue
void endInsert(queue *player, node *cards) {
    node *aux;
    if (cards->prox == nullptr) {
        std::cout << "endInsert of Empty cards!";
        return;
    }
    cards = cards->prox;
    if (isEmpty(player)) {
        player->fr->prox = cards;
        for (aux = cards; aux->prox != nullptr; aux = aux->prox);
        player->tr = aux;
        if (player->tr->prox != NULL) {
            std::cout << "Error in endInsert";
        }
    } else {
        for (aux = cards; aux->prox != nullptr; aux = aux->prox);
        player->tr = aux;
        if (player->tr->prox != NULL) {
            std::cout << "Error in endInsert";
        }
    }

}

bool isEmpty(queue *player) {
    if (player->fr == player->tr)
        return true;
    else
        return false;
}


// Add a card to cards queue
void cardPop(node *listCards, int card) {
//    if (listCards->prox == nullptr) {
//        listCards->prox = new node;
//        listCards->prox->elem = card;
//    } else {
    node *temp = listCards;
    for (; temp->prox != nullptr; temp = temp->prox);
    temp->prox = new node;
    temp = temp->prox;
    temp->prox = nullptr;
    temp->elem = card;
//    }
}

void randomInicializeCards(node *listCards) {
    node *Shuffle, *aux, *temp;
    int i, j, n = 52;

    time_t t;
    srand((unsigned) time(&t));

    cardsInitialize(&Shuffle);
    Shuffle->prox = new node;
    aux = Shuffle->prox;

    for (i = 4; i < 56; i++) {
        aux->elem = i;
        aux->prox = new node;
        aux = aux->prox;
    }

    aux->elem = i;
    aux->prox = nullptr;

    while (Shuffle->prox != nullptr and n > 0) {
        i = rand() % n + 5;
        for (aux = Shuffle, j = 5; j < i; aux = aux->prox, j++);
        temp = aux->prox ;
        cardPop(listCards, temp->elem);
        aux->prox = temp->prox;
        n--;
    }

}

void divideCards(node *listCards, node **cards1, node **cards2) {
    node *aux;
    int i;
    for (aux = listCards, i = 1; i < 26; aux = aux->prox, i++);
    *cards1 = listCards;
    *cards2 = new node;
    (*cards2)->prox = aux->prox;
    aux->prox = nullptr;

}

void printTop(queue *player) {
    std::string naipe;
    char number;
    int temp = player->fr->prox->elem - 1;

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
            number = '0' + (temp / 4);
            break;
        case 10:
            number = 'D';
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

//    std::cout << "card = " << temp + 1 << " which is " << number << " de " << naipe << std::endl;
    std::cout << number << " de " << naipe << std::endl;
}


