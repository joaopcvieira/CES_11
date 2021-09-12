//
// Created by joao_vieira on 16/08/2021.
//

#include <iostream>
#include "Fila.h"

bool Vazia(fila F) {
    if (F.fr == F.tr)
        return true;
    else
        return false;
}

void Esvaziar(fila *F) {
    nohF *temp;
    while (F->fr != F->tr) {
        for (temp = F->fr; temp->prox != F->tr; temp = temp->prox);
        F->tr = temp;
        free(temp->prox);
    }

}

void InicFila(fila *F) {
    F->fr = (nohF *) malloc(sizeof(nohF));
    F->tr = F->fr;

}

void Entrar(int x, fila *F) {
    if (F->fr == F->tr) {
        F->tr = (nohF *) malloc(sizeof(nohF));
        F->fr->prox = F->tr;
    } else {
        F->tr->prox = (nohF *) malloc(sizeof(nohF));
        F->tr = F->tr->prox;
    }

    F->tr->elem = x;
    F->tr->prox = nullptr;
}

void Deletar(fila *F) {
    nohF *temp;
    temp = F->fr->prox;
    if (F->fr->prox == F->tr)
        F->tr = F->fr;
    else
        F->fr->prox = temp->prox;
    free(temp);
}

int Frente(fila F) {
    if (F.fr == F.tr) {
        std::cout << "Frente de Fila Vazia";
        return -1;
    } else
        return F.fr->prox->elem;
}

void EscreverFila(fila F) {
    nohF *temp;
    for (temp = F.fr->prox; temp != F.tr; temp = temp->prox)
        std::cout << temp->elem << std::endl;
    std::cout << temp->elem << std::endl;

}
