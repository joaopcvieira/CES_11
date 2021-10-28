//
// Created by joao_vieira on 27/10/2021.
//

#include "graph.h"

/** old try **/

/*GRAPH *graph_create(int order) {
    GRAPH *g = (GRAPH *) malloc(sizeof(GRAPH));
    g->order = order;
    g->edges = (bool *) malloc(order * (order + 1) / 2 * sizeof(bool));
    for (int i = 0; i < order * (order + 1) / 2; ++i)
        g->edges[i] = false;
    return g;
}

 Aresta (u,v) tal que u >=v encontra -se na posicao
* u(u +1)/2+ v do array unidimensional .
bool graph_has_edge(GRAPH *g, int u, int v) {
    if (u < v)
        return g->edges[u * (u + 1) / 2 + v];
    else
        return g->edges[v * (v + 1) / 2 + u];
}
*/


GRAPH *graph_create(int order) {
    GRAPH *g = (GRAPH *) malloc(sizeof(GRAPH));
    g->order = order;
    g->neighbors = (NEIGHBOR **) malloc(order * sizeof(NEIGHBOR *));

    for (int i = 0; i < order; ++i)
        g->neighbors[i] = NULL;

    return g;
}

LIST position_list_create(int order) {
    LIST returnList;
    list_create(&returnList, order);
    return returnList;
}

void set_positions_in_list(LIST positions) {
    POSITION temp;
    bool nomeRepetido = false;
    for (int i = 0, r = 0; i < positions.size; i++) {
        for (int j = 0; j < i; j++) {
            if (strcmp(author[i].name, author[j].name) == 0)
                nomeRepetido = true;
        }
        if (!nomeRepetido) {
            strcpy(temp.name, author[i].name);
            temp.pos = r;
            r++;
        }
        nomeRepetido = false;
    }


}

int get_position(LIST *positions, char *name) {
    LIST *aux = positions;
    for (int i = 0; i < positions->size; i++, aux = aux->prox) {
        if (strcmp(positions->element.name, name) == 0)
            return i;
    }
    return -1;
}


void dijkstra(GRAPH *g, int u) {
    int p[g->order]; // init as -1
    int d[g->order]; // init as MAX_INT
    LIST U;// add ={1 , 2 , ... , |V|}

    LIST aux = U;
    for (int i = 1; i < sizeDeAlgo; i++)
        list_insert(U, i);
        NEIGHBOR *v;

    d[u] = 0;
    while (!is_empty(U)) {
        v = min_neighbor(d);
        remove(U, v);
        for (NEIGHBOR *n = v->next; n; n = n->next)
            // d[{v,n}] = d[{v,n} - > index ]
            if (d[v] + w(v, n) < d[n]) {
                d[n] = d[v] + w(v, n);
                p[n] = v;
            }
    }
