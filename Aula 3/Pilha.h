//
// Created by joao_vieira on 16/08/2021.
//

// Pilha para INTEIROS
#ifndef CES_11_PILHA_H
#define CES_11_PILHA_H

typedef struct nohP nohP;
struct nohP{
    int elem;
    nohP *prox;
};



typedef nohP *pilha;

// normal functions
void InicPilha(pilha *);
void Empilhar (int, pilha *);
void Desempilhar (pilha *);
int Topo(pilha);
void Esvaziar (pilha *);
bool Vazia(pilha);
void EscreverPilha(pilha);


#endif //CES_11_PILHA_H
