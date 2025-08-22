#include <stdio.h>
#include <stdlib.h>

typedef struct lint_nodo {
int valor;
struct lint_nodo *prox;
} *LInt;

int maxCresc(LInt l){

    int max = 0;
    int n = 1;  // a sequencia sera no minimo 1 sempre

    if(l == NULL) return 0;
    else{
        LInt aux = l;
        while(aux->prox != NULL){
            if(aux->valor < aux->prox->valor)  // se o valor atual é menor que o proximo
                n++;                        // acrescenta o contador da sequencia
            else{    //  se nao
                if(n > max) max = n;  // checa se o n obtido é maior que o maximo atual
                n = 1;               // reseta o contador
            }
            aux = aux->prox;            //avança
        }
    }
    return max;
}

LInt newList(int x){

    LInt list = malloc(sizeof(struct lint_nodo));    
    list->valor = x;
    list->prox = NULL;

    return list;
}

void insert(LInt l, int x){

    LInt list = malloc(sizeof(struct lint_nodo));    
    list->valor = x;
    list->prox = NULL;

    if(l == NULL){
        l = list;
    } else {
        LInt aux = l;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = list;
    }
}

void printL(LInt l){

    if(l == NULL) printf("Arvore vazia");
    else{
        LInt aux = l;
    while(aux!= NULL) {
        printf("%d -> ", aux->valor);
        aux = aux->prox;
    }
    printf("NULL\n");
}
}

int main(){

    LInt list = newList(1);
    insert(list, 2);
    insert(list, 3);
    insert(list,2);
    insert(list,1);
    insert(list,4);
    insert(list,10);
    insert(list,12);
    insert(list,5);
    insert(list,4);
    printL(list);

    int c = maxCresc(list);
    printf("A maior sequencia e %d", c);
    return 0;

}