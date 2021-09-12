//
// Created by joao_vieira on 16/08/2021.
//

#ifndef CES_11_FILA_H
#define CES_11_FILA_H

typedef struct nohF nohF;
typedef struct fila fila;
struct nohF {
    int elem;
    nohF *prox;
};
struct fila {
    nohF *fr, *tr;
};


void Entrar(int, fila *);

void Deletar(fila *);

int Frente(fila);

void InicFila(fila *);

void Esvaziar(fila *);

bool Vazia(fila);

void EscreverFila(fila);

#endif //CES_11_FILA_H
