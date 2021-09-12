/* ********************************* */
/* Aluno: João Pedro Couto Vieira */
/* CES-11: Algoritmos e Estruturas de Dados */
/* Descrição: . */
/* ********************************* */

/* main.c - Calculadora de Notação Polonesa Reversa  */

#include <stdio.h>
#include <stdlib.h>
#include "adt_stack.h"

int main() {
    char cmd = '0';
    double n1, n2;
    stack_t polishStack;
    adt_initStack(&polishStack);

    // loop de leitura de operandos e operadores
    while (scanf(" %c", &cmd) != EOF) {

        char temp[14];
        char *eptr;
        // switch-case para cada operando
        switch (cmd) {
            case '+':
                n1 = adt_topStack(polishStack);
                adt_popStack(&polishStack);
                n2 = adt_topStack(polishStack);
                adt_popStack(&polishStack);
                adt_pushStack(&polishStack, n1 + n2);
                break;

            case '-':
                n1 = adt_topStack(polishStack);
                adt_popStack(&polishStack);
                n2 = adt_topStack(polishStack);
                adt_popStack(&polishStack);
                adt_pushStack(&polishStack, n1 - n2);
                break;

            case '/':
                n1 = adt_topStack(polishStack);
                adt_popStack(&polishStack);
                n2 = adt_topStack(polishStack);
                adt_popStack(&polishStack);
                adt_pushStack(&polishStack, n1 / n2);
                break;

            case '*':
                n1 = adt_topStack(polishStack);
                adt_popStack(&polishStack);
                n2 = adt_topStack(polishStack);
                adt_popStack(&polishStack);
                adt_pushStack(&polishStack, n1 * n2);
                break;

            case 'c':
                adt_emptyStack(&polishStack);
                break;


            case '~':
                n1 = adt_topStack(polishStack);
                adt_popStack(&polishStack);
                adt_pushStack(&polishStack, -n1);
                break;

            case '=':
                // impressao do resultado da conta ao final (=)
                n1 = adt_topStack(polishStack);
                adt_popStack(&polishStack);
                printf("Resultado: %f\n", n1);
                adt_emptyStack(&polishStack);
                break;

            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                temp[0] = cmd;
                int i;
                for (i = 1; temp[i - 1] != ' '; i++)
                    scanf("%c", &temp[i]);
                eptr = &temp[i - 1];
                adt_pushStack(&polishStack, strtod(temp, &eptr));
                break;

            default:
                printf("ERRO!\n");
                break;
        }
    }



}