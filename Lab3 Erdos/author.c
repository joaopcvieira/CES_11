//
// Created by joaop on 23/10/2021.
//

#include "author.h"

void readAuthors(int numPapers) {
    int numAuthors = 0; //number of authors in all papers
    int p = 0; //position of expr => expr[p]
    int i, node;


    for (node = 0; node < numPapers; node++) {

        fgets(expr, MAX_EXPR, stdin);
        p = 0; //setting cursor to the beginning

//      the list of names end when expr[p] = ':'
        while (expr[p] != ':') {
//          Cleaning blank spaces
            while (expr[p] == ' ')
                p++;

//            every name have a ',' in it and names are limited by another ','
            for (i = 0; expr[p] != ','; i++, p++) {
                author[numAuthors].name[i] = expr[p];
            }

            author[numAuthors].name[i] = expr[p];
            i++;
            p++;

            for (; expr[p] != ','; i++, p++) {
                author[numAuthors].name[i] = expr[p];
            }

//            saving the paper in which the author is
            author[numAuthors].paper = node;

//            saving erdos Num if he is Erdos or with erdos, otherwise
//            it receives a temporary non-valid number, -99
//              TODO ajustar essa porra aqui
            if (strcmp(author[numAuthors].name, "Erdos, P.") == 0)
                author[numAuthors].erdosNum = 0;
            else
                author[numAuthors].erdosNum = -99;
        }
    }


}
