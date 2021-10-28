#include <stdio.h>
#include "author.h"

int main() {

    int scenario, papers, names;

// Read scenario
    scanf("%d %d %d", &scenario, &papers, &names);

// Read authors names
    readAuthors(papers);


    /*

     * construct tree with all the given relation-ships
     * determine the shortest path in tree
     *
     *
     * print authors names with erdos number
     *      remember that -1 implies in "infinity"
     *
     *
     */


    return 0;
}
