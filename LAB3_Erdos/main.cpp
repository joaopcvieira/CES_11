/* ********************************* */
/* Aluno: João Pedro Couto Vieira */
/* CES-11: Algoritmos e Estruturas de Dados */
/* Descrição: . */
/* ********************************* */

#include <iostream>
#include <cstdio>
#include <string>

#define MAX_AUTHORS 100
#define MAX_EXPR 1000

/** used structs **/
typedef struct {
    std::string name; //author's name
    int erdosNum; // author's Erdos number
    int paper;  //paper he's inserted in
} object;

typedef struct graph GRAPH;
typedef struct neighbor NEIGHBOR;

struct neighbor {
    int erdosNum; // author's Erdos number
    std::string name;
    NEIGHBOR *next;
};

struct graph {
    int order;
    NEIGHBOR *neighbors[MAX_AUTHORS];
};

typedef struct list_st list_t;
struct list_st {
    std::string author;
    list_t *next;
};

/** used functions **/
void dijkstra(GRAPH *, int);

bool is_empty(list_t);

void list_push(list_t *, std::string);

void remove(list_t *list, std::string);

int name_to_pos(std::string, GRAPH *);

NEIGHBOR *min_neighbor(int *dist, list_t U, GRAPH *g);


int main() {

    char expr[MAX_EXPR];
    object author[MAX_AUTHORS];
    int scenario, papers, names;


    int scenarioCounter = 0;
    scanf(" %d", &scenario);
    while (scenarioCounter < scenario) {
        GRAPH grafo;


        scanf("%d %d", &papers, &names);
        int numAuthors = 0; //number of authors in all papers
        int p = 0; //position of expr => expr[p]
        int i, j;
        int node;
        char lixo;
        const std::string erdos = "Erdos, P.";

        // read a clean line
        scanf("%c", &lixo);

        /** read and save all authors **/
        for (node = 0; node < papers; node++) {

            fgets(expr, MAX_EXPR, stdin);

            p = 0; //setting cursor to the beginning

//      the list of names end when expr[p] = ':'
            do {
                std::string tempName = "";

//          Cleaning blank spaces
                while (expr[p] == ' ')
                    p++;
//            every name have a ',' in it and names are limited by another ','
                for (i = 0; expr[p] != ','; i++, p++) {
                    tempName += expr[p];
                }

                tempName += expr[p];
                i++;
                p++;

                for (; expr[p] != ',' and expr[p] != ':'; i++, p++) {
                    tempName += expr[p];
                }

                if (tempName[tempName.length()-1] == ' ')
                    tempName =  tempName.substr( 0,tempName.length() -1);

                author[numAuthors].name = tempName;
                tempName = "";
//            saving the paper in which the author is
                author[numAuthors].paper = node;
                numAuthors++;

            } while (expr[p++] != ':');
        }


        /** insert names in graph **/
        for (i = 0, grafo.order = 0; i < numAuthors; i++, grafo.order++) {
            grafo.neighbors[grafo.order] = (NEIGHBOR *) (malloc(sizeof(NEIGHBOR)));

            grafo.neighbors[grafo.order]->name = "test";

            int repeated_num;

            // check if name already exists
            bool repeated_name = false;
            for (j = 0; j < i && j <= grafo.order; j++) {
                if (author[i].name == grafo.neighbors[j]->name) {
                    grafo.order--;
                    repeated_name = true;
                    repeated_num = j;
                }
            }

            //if it doesn't exist, then add its name and connections
            //if it already exists, just add its connections
            if (not repeated_name) {
                // create a temporary line of connections of those in same paper (node)
                NEIGHBOR *tempLine, *aux;
                tempLine = (NEIGHBOR *) malloc(sizeof(neighbor));
                aux = tempLine;

                for (int k = 0; k < numAuthors; k++)
                    if (author[i].paper == author[k].paper and i != k) {
                        aux->next = new NEIGHBOR;
                        aux->next->name = author[k].name;
                        aux = aux->next;
                        aux->next = nullptr;

                    }

                grafo.neighbors[grafo.order]->name = author[i].name;
                grafo.neighbors[grafo.order]->next = tempLine->next;
            } else {
                // create a temporary line of connections of those in same paper (node)
                NEIGHBOR *tempLine, *aux;
                tempLine = (NEIGHBOR *) malloc(sizeof(neighbor));
                aux = tempLine;

                for (int k = 0; k < numAuthors; k++)
                    if (author[i].paper == author[k].paper and i != k) {
                        aux->next = (NEIGHBOR *) malloc(sizeof(neighbor));
                        aux->next->name = author[k].name;
                        aux = aux->next;
                        aux->next = nullptr;
                    }
                if (grafo.neighbors[repeated_num]->next == nullptr) {
                    grafo.neighbors[repeated_num]->next = tempLine->next;
                } else {
                    for (aux = grafo.neighbors[repeated_num]->next; aux->next != nullptr; aux = aux->next);
                    aux->next = tempLine->next;
                }
            }

            //if author is Erdos, then erdosnum = 0, otherwise it is 1000
            if (grafo.neighbors[grafo.order]->name == erdos)
                grafo.neighbors[grafo.order]->erdosNum = 0;
            else
                grafo.neighbors[grafo.order]->erdosNum = 1000;


        }

        /** Dijkstra's algorithm **/

        dijkstra(&grafo, name_to_pos(erdos, &grafo));
        dijkstra(&grafo, name_to_pos(erdos, &grafo));

        /** get names to print and print them **/

        std::cout << "Scenario " << scenarioCounter + 1 << std::endl;
        for (int j = 0; j < names; j++) {
            std::string nameToPrint;
            char temp;

            while (scanf("%c", &temp) != EOF and temp != '\n')
                nameToPrint += temp;

            int pos = name_to_pos(nameToPrint, &grafo);

            if (pos >= 0) {
                if (grafo.neighbors[pos]->erdosNum < 100)
                    std::cout << nameToPrint << " " <<
                              grafo.neighbors[pos]->erdosNum << std::endl;
                else
                    std::cout << nameToPrint << " infinity" << std::endl;
            } else
                std::cout << nameToPrint << " infinity" << std::endl;
        }


        /** next scenario **/
        scenarioCounter++;
        for (i = 0; i <= numAuthors; i++) {
            author[i].erdosNum = 1000;
        }
    }


    return 0;
}

void dijkstra(GRAPH *g, int u) {

    int d[g->order]; // init as MAX_INT
    list_t U;// add ={1 , 2 , ... , |V|}
    NEIGHBOR *v;

    U.next = nullptr;
    for (int i = 0; i < g->order; i++) {
        d[i] = 10000;
        list_push(&U, g->neighbors[i]->name);
    }

    d[u] = 0;
    while (!is_empty(U)) {
        v = min_neighbor(d, U, g);
        remove(&U, v->name);
        for (NEIGHBOR *n = v->next; n; n = n->next)
            if (d[name_to_pos(v->name, g)] + 1 < d[name_to_pos(n->name, g)]) {
                d[name_to_pos(n->name, g)] = d[name_to_pos(v->name, g)] + 1;
            }
    }

    for (int i = 0; i < g->order; i++) {
        g->neighbors[i]->erdosNum = d[i];
    }
}


NEIGHBOR *min_neighbor(int *dist, list_t U, GRAPH *g) {
    if (not is_empty(U)) {
        list_t *aux;
        int minErdosNum;
        std::string minName;

        minErdosNum = dist[name_to_pos(U.next->author, g)];
        minName = U.next->author;

        for (aux = U.next; aux != nullptr; aux = aux->next) {
            if (dist[name_to_pos(aux->author, g)] < minErdosNum) {
                minErdosNum = g->neighbors[name_to_pos(aux->author, g)]->erdosNum;
                minName = g->neighbors[name_to_pos(aux->author, g)]->name;
            }
        }
        return g->neighbors[name_to_pos(minName, g)];
    }
    return nullptr;
}


int name_to_pos(std::string name, GRAPH *g) {
    for (int i = 0; i < g->order; i++)
        if (g->neighbors[i]->name == name)
            return i;

    return -1;
}

bool is_empty(list_t list) {
    if (not list.next)
        return true;
    else
        return false;
}

void list_push(list_t *list, std::string author) {
    list_t *aux = list;
    if (list->next == nullptr) {
        list->next = new list_t;
        list->next->author = author;
        list->next->next = nullptr;

    } else {
        aux = list->next;
        list->next = new list_t;
        list->next->author = author;
        list->next->next = aux;
    }

}

void remove(list_t *list, std::string author) {
    list_t *aux;
    for (aux = list; author != aux->next->author and aux->next != nullptr; aux = aux->next);
    if (aux->next != nullptr)
        aux->next = aux->next->next;
    else
        std::cout << "\n\nno name removed";
}