#include "50ABin.h"
#include <stdio.h>
#include <stdlib.h>

int main(){

    ABin arv = init(10);

    insere(arv, 20);
    insere(arv, 5);
    insere(arv, 100);
    insere(arv, 800);
    insere(arv, 2);
    insere(arv, 7);

    printf("Arvore");
    printArvVisual(arv, 0);

    int height = altura(arv);

    printf("Altura: %d\n", height);

    printf("Clone:");

    ABin clone = cloneAB(arv);

    printArvVisual(clone, 0);

    mirror(arv);

    printf("Arvore invertida:\n");
    printArvVisual(arv, 0);

    return 0;
}