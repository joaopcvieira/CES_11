#include <iostream>
#include "Pilha.h"
#include "Fila.h"

int main() {
//    Teste para pilhas
/*
        pilha P;
        int n;

        std::cout << "Hello, World!" << std::endl;

        InicPilha(&P);
        std::cout << "How many numbers?" << std::endl;
        std::cin >> n;
        for (int i = 0; i < n; i++) {
            int temp;
            std::cout << "Type the " << i + 1 << " number  ";
            std::cin >> temp;
            Empilhar(temp, &P);
        }
        std::cout << "Escrevendo a pilha...";
        EscreverPilha(P);

//    desempilhando o ultimo numero
        std::cout << "\n\nvamos desempilhar o numero " << Topo(P) << std::endl;
        Desempilhar(&P);

        std::cout << "Escrevendo a pilha...\n";
        EscreverPilha(P);
*/

//Teste para filas
    fila F;
    int n;


    InicFila(&F);
    std::cout << "How many numbers?" << std::endl;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        int temp;
        std::cout << "Type the " << i + 1 << " number  ";
        std::cin >> temp;
        Entrar(temp, &F);
    }
    std::cout << "Escrevendo a fila...\n";
    EscreverFila(F);

//    desempilhando o ultimo numero
    std::cout << "\n\nvamos desempilhar o numero " << Frente(F) << std::endl;
    Deletar(&F);

    std::cout << "Escrevendo a fila...\n";
    EscreverFila(F);
    return 0;
}
