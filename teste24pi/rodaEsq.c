#include <stdio.h>
#include <stdlib.h>

typedef struct abin_nodo {
int valor;
struct abin_nodo *esq, *dir;
} *ABin;

void rodaEsq(int a[], int N, int r){

    int i = 0;
    int copy = r;

    int *aux = malloc(N * sizeof(int));

    for(r; r < N; r++){
        aux[i] = a[r];
        i++;
    }


    for(int j = 0; j < copy; j++){
        aux[i] = a[j];
        i++;
    }

    int j = 0;

    for(int i = 0; i<N; i++){
        a[i] = aux[j];
        j++;
    }

    free(aux);
    
}

ABin newABin(int x){

    ABin a = malloc(sizeof(struct abin_nodo));
    if(!a){
        return NULL;
    }
    a->valor  = x;
    a->esq = NULL;
    a->dir = NULL;

    return a;
}

ABin inserir(ABin a, int x){

    if(a == NULL){
        ABin novo = malloc(sizeof(struct abin_nodo));
        if(!novo) return NULL;
        novo->valor = x;
        novo->esq = NULL;
        novo->dir = NULL;
        return novo;
    }
    else
    {
        if(a->valor > x)
            a->esq = inserir(a->esq, x);
        else
            a->dir = inserir(a->dir, x);
    }
}

void printABin(ABin a, int nivel) {
    if (a == NULL) return;

    printABin(a->dir, nivel + 1);

    for (int i = 0; i < nivel; i++)
        printf("   ");  // indentação

    printf("%d\n", a->valor);

    printABin(a->esq, nivel + 1);
}

ABin folhaEsq(ABin a){

    if(a == NULL) return NULL;
    if(a->esq == NULL)  
        return a;
    else
        return folhaEsq(a->esq);
}

int main(){

    /*int num[] = {1,2,3,4,5,6};

    rodaEsq(num, 6, 2);

    for(int i = 0; i<6; i++){
        printf("%d ", num[i]);
    }*/

    ABin arv = newABin(10);
    inserir(arv, 2);
    inserir(arv, 5);
    inserir(arv, 11);
    inserir(arv, 3);
    printABin(arv, 0);

    ABin f = folhaEsq(arv);

    printf("O valor do nodo mais a esquerda e %d.", f->valor);

}
    