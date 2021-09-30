//
// Created by joao_vieira on 29/08/2021.
//

#include "GameMode.h"

bool NormalRound(queue *player1, queue *player2) {
    int card1, card2;
    node *onTable = nullptr;

    while (not isEmpty(player1) and not isEmpty(player2)) {
        std::cout << "\n\tStarting a Normal Round:";
        cardsInitialize(&onTable);

        card1 = topDelete(player1);
        card2 = topDelete(player2);
        std::cout << "\nPlayer One plays: " << CardTranslate(card1);
        std::cout << "\nPlayer Two plays: " << CardTranslate(card2) << std::endl;

        cardPop(onTable, card1);
        cardPop(onTable, card2);

        if (((card1 + 4) / 4) > ((card2 + 4) / 4)) {
            std::cout << "\nTherefore Player One won!";
            endInsert(player1, onTable);
        } else if (((card1 + 4) / 4) < ((card2 + 4) / 4)) {
            std::cout << "\nTherefore Player Two won!";
            endInsert(player2, onTable);
        } else {
            std::cout << "\nOOHH! It`s a Tie!!\nLet`s start the War! ";
            Tie(player1, player2, onTable);
        }


        if (isEmpty(player1) or isEmpty(player2)) {
            std::cout << "\n\nOhh, it seams that a player is out of cards"
                      << "\nThis means our game has ended!!\n\n";
            return true;
        } else
            return false;
    }

    return true;
}

bool Tie(queue *player1, queue *player2, node *onTable) {
    int card1[3], card2[3];

    if (not isEmpty(player1) and not isEmpty(player2)) {
        card1[0] = topDelete(player1);
        card2[0] = topDelete(player2);
        cardPop(onTable, card1[0]);
        cardPop(onTable, card2[0]);

        if (not isEmpty(player1) and not isEmpty(player2)) {
            card1[1] = topDelete(player1);
            card2[1] = topDelete(player2);
            cardPop(onTable, card1[1]);
            cardPop(onTable, card2[1]);


            if (not isEmpty(player1) and not isEmpty(player2)) {
                card1[2] = topDelete(player1);
                card2[2] = topDelete(player2);
                cardPop(onTable, card1[2]);
                cardPop(onTable, card2[2]);

                std::cout << "\nPlayer One played" << "\n\t" << CardTranslate(card1[0]) <<
                          ";\n\t" << CardTranslate(card1[1]) << "; and\n\t" << CardTranslate(card1[2]);

                std::cout << "\nPlayer Two played" << "\n\t" << CardTranslate(card2[0]) <<
                          ";\n\t" << CardTranslate(card2[1]) << "; and\n\t" << CardTranslate(card2[2]) << std::endl;

                if (((card1[2] + 4) / 4) > ((card2[2] + 4) / 4)) {
                    std::cout << "\nTherefore Player One won the WAR!";
                    endInsert(player1, onTable);
                } else if (((card1[2] + 4) / 4) < ((card2[2] + 4) / 4)) {
                    std::cout << "\nTherefore Player Two won the WAR!";
                    endInsert(player2, onTable);
                } else {
                    std::cout << "\nOOHH! It`s a Tie AGAIN!!\nLet`s go to another War! ";
                    Tie(player1, player2, onTable);
                }
            }
        }
        if (isEmpty(player1) or isEmpty(player2))
            return true;
        else
            return false;
    }

    return true;
}

int Winner(queue *player1, queue *player2) {
    if (isEmpty(player1)) { return 2; }

    else if (isEmpty(player2)) { return 1; }

    else { return 0; }

}

std::string CardTranslate(int card) {
    std::string translated;
    card;

//    Defining patter for cards
//    Using Truco`s "manilhas" priority of "naipes"

    switch (card / 4) {
        case 1:
            translated = "A";
            break;
//        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
            translated = std::to_string((card / 4));
            break;
        case 10:
            translated = "10";
            break;
        case 11:
            translated = "J";
            break;
        case 12:
            translated = "Q";
            break;
        case 13:
            translated = "K";
            break;
        default:
            translated = "!";
            break;

    }

    translated += " de ";

    switch (card % 4) {
        case 0:
            translated += "Paus";
            break;
        case 1:
            translated += "Copas";
            break;
        case 2:
            translated += "Espadas";
            break;
        case 3:
            translated += "Ouros";
            break;
    }
    return translated;
}
