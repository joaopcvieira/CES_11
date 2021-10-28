#include <iostream>
#include "AdtQueue.h"
#include "GameMode.h"


int main() {

    queue *player1 = new queue, *player2 = new queue;
    node *cards = new node;
    node *card1 = new node, *card2 = new node;
    queueInitialize(player1);
    queueInitialize(player2);


//    cardsInitialize(cards);

/*    for (unsigned int i = 1; i <= 56; i++) {
       cardPop(cards, i);
   }
*/
//Inicializing player`s cards
    randomInicializeCards(cards);
    divideCards(cards, &card1, &card2);

//    for (unsigned int i = 4; i <= 56;) {
//        cardPop(card1, i++);
//        cardPop(card2, i++);
//    }
    endInsert(player1, card1);
    endInsert(player2, card2);
//
//    card1->prox = nullptr;
//    card2->prox = nullptr;



    while (not isEmpty(player1) and not isEmpty(player2)) {
        NormalRound(player1, player2);
        std::cout << "\n\nClick to continue...";
        getchar();
        std::cout << "\n";
    }

    /*  std::cout << "\nPlayer 1`s cards: ";
      for (unsigned int i = 1; i <= 28; i++) {
          printTop(&player1);
          topDelete(&player1);
      }
      std::cout << "\nPlayer 2`s cards: ";
      for (unsigned int i = 1; i <= 28; i++) {
          printTop(&player2);
          topDelete(&player2);
      } */

    std::cout << "\n\n\n\tSOOOO, the winner was Player number " <<
              Winner(player1, player2) << "!!!!!!";

    return 0;
}
