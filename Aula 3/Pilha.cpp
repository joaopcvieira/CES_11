//
// Created by joao_vieira on 16/08/2021.
//

#include "Pilha.h"
#include <iostream>

void Empilhar(int m, pilha *P) {
    nohP *temp;
    temp = *P;
    *P = (nohP *) malloc(sizeof(nohP));
    (*P)->elem = m;
    (*P)->prox = temp;

}

void Desempilhar(pilha *P) {
    if (*P != nullptr) {
        nohP *temp;
        temp = *P;
        *P = (*P)->prox;
        free(temp);

    } else
        std::cout << "Desempilhar pilha vazia" << std::endl;

}

int Topo(pilha P) {
    if (P != nullptr)
        return P->elem;
    else
        std::cout << "Topo de pilha vazia" << std::endl;
}

void InicPilha(pilha *P) {
    *P = nullptr;
}

void Esvaziar(pilha *P) {
    if (P != nullptr) {
        nohP *temp, *aux1;
        for (temp = *P; temp->prox != nullptr; temp = temp->prox);

        while (temp != *P) {
            for (aux1 = *P; aux1->prox != temp; aux1 = aux1->prox) {
                free(temp->prox);
                temp = aux1;
            }
        }

    } else
        std::cout << "Ja esta vazia" << std::endl;

}

bool Vazia(pilha P) {
    if (P == nullptr)
        return true;
    else
        return false;
}

void EscreverPilha(pilha P) {
    nohP *temp, *aux1;

    for (temp = P; temp->prox != nullptr; temp = temp->prox);
    while (temp != P) {
        for (aux1 = P; aux1->prox != temp; aux1 = aux1->prox);
        std::cout << temp->elem << std::endl;
        temp = aux1;
    }
    std::cout << temp->elem << std::endl;
}
