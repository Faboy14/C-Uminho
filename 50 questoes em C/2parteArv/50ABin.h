#ifndef _50ABIN_H_
#define _50ABIN_H_

typedef struct nodo {
    int valor;
    struct nodo *esq, *dir;
    } *ABin;

typedef struct lligada {
    int valor;
    struct lligada *prox;
} *LInt;

ABin init(int valor);
ABin insere(ABin arv, int x);
void printArvVisual(ABin arv, int nivel);
int altura (ABin);
ABin cloneAB (ABin);
void mirror(ABin arv);
void inorder(ABin arv, LInt *q);

#endif 


    