#include "50ABin.h"
#include <stdio.h>
#include <stdlib.h>

ABin init(int valor){

    ABin l = malloc(sizeof(struct nodo));
    l->valor = valor;
    l->esq = NULL;
    l->dir = NULL;

    return l;
}

ABin insere(ABin arv, int x){

    if(arv == NULL){
        return init(x);
    }
    else
    {
        if(arv->valor > x)
            arv->esq = insere(arv->esq, x);
        else
            arv->dir = insere(arv->dir, x); 
    }

    return arv;
}

int altura(ABin arv){

    if(arv == NULL)
        return -1;

    int alturaesq = altura(arv->esq);
    int alturadir = altura(arv->dir);
    
    if(alturaesq > alturadir)
        return 1 + alturaesq;
    else 
        return 1 + alturadir;

}

ABin cloneAB(ABin arv){
    
    if(arv == NULL)
        return NULL;
    ABin clone = malloc(sizeof(struct nodo));
    clone->valor = arv->valor;
    clone->esq = cloneAB(arv->esq);
    clone->dir = cloneAB(arv->dir);

    putchar('\n');

    return clone;
    
}

void mirror(ABin arv){

    if(arv == NULL){
        return;
    }

    ABin temp = arv->esq;
    arv->esq = arv->dir;
    arv->dir = temp;

    mirror(arv->esq);
    mirror(arv->dir);

}

void inorder(ABin arv, LInt *q) {
    if (arv == NULL) 
        return;

    // 1) percorre à esquerda, preenchendo a lista
    inorder(arv->esq, q);

    // 2) cria o nó da lista para o valor do 'arv'
    *q = malloc(sizeof **q);
    (*q)->valor = arv->valor;
    (*q)->prox  = NULL;

    // faz o 'q' apontar para o campo prox desse nó,
    // onde o próximo elemento será inserido
    q = &(*q)->prox;

    // 3) percorre à direita, continuando a preencher
    inorder(arv->dir, q);
}

void preorder(ABin arv, LInt *q) {
    if (arv == NULL) 
        return;

    *q = malloc(sizeof(struct lligada));
    (*q)->valor = arv->valor;
    (*q)->prox  = NULL;

    q = &(*q)->prox;

    preorder(arv->esq, q);
    preorder(arv->dir, q);
}

void printArvVisual(ABin arv, int nivel) {
    if (arv == NULL) {
        return;
    }

    // Primeiro imprime a subárvore direita
    printArvVisual(arv->dir, nivel + 1);

    // Imprime o nó atual com indentação correspondente ao nível
    for (int i = 0; i < nivel; i++) {
        printf("    "); // Adiciona 4 espaços para cada nível
    }
    printf("%d\n", arv->valor);

    // Depois imprime a subárvore esquerda
    printArvVisual(arv->esq, nivel + 1);
}