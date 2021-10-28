//
// Created by joao_vieira
//

#ifndef LAB3_ERDOS_GRAPH_H
#define LAB3_ERDOS_GRAPH_H

#include <stdbool.h>
#include <stdlib.h>
#include "author.h"
#include "list.h"

/** old try **/
/*typedef struct {
    int order;
    bool *edges;
} GRAPH;*/

typedef struct graph GRAPH;
typedef struct neighbor NEIGHBOR;

struct neighbor {
    int index;
    NEIGHBOR *next;
};

struct graph {
    int order;
    NEIGHBOR **neighbors;
};

GRAPH *graph_create(int);

LIST position_list_create(int);

bool graph_has_edge(GRAPH *, int, int);

int get_position(LIST *, char *);

void set_positions_in_list(LIST);

#endif //LAB3_ERDOS_GRAPH_H
