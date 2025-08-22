#include <stdio.h>
#include <stdlib.h>

typedef struct lint_nodo {
int valor;
struct lint_nodo *prox;
} *LInt;

//que apaga o n-ésimo elemento de uma lista ligada (para n == 0 a função deverá remover o primeiro
//elemento). Se tal não for possível a função deverá devolver um código de erro

int delete(int n, LInt *l){

    if(l == NULL)
        return -1;              //lista vazia erro
    if(n == 0){                 // se n == 0, remove o primeiro elemento
        LInt temp = *l;          // guarda o primeiro elemento em uma variavel para ser liberado
        (*l) = (*l)->prox;         // o primeiro elemento passa a ser o segundo
        free(temp);             //libera o primeiro elemento da memoria
    } else {
        LInt previous = NULL;
        LInt current = *l;
        LInt next;
        while(n >= 1){                      // o loop so para quando n = 1, significa que parei em cima da caixa que busco
            previous = current;           // avanca o ponteiro anterior
            current = current->prox;    // avanca o ponteiro atual
            if(current == NULL)         // se o ponteiro atual for nulo, significa que n é maior que o tamanho da lista
                return -1;  
            n--;                  // decrementa n
        }
        LInt temp = current;        // guarda o elemento que quero remover
        next = current->prox;       // guarda o proximo elemento
        previous->prox = next;      // o ponteiro anterior passa a apontar para o proximo elemento que guardei
        current->prox = NULL;           // o ponteiro atual passa a ser nulo
        current = next;         // o ponteiro atual passa a ser o proximo elemento  
        free(temp);                 // libera o elemento que quero remover
    }
    return 0;
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

    LInt list = newList(10);
    insert(list, 5);
    insert(list, 20);
    insert(list,15);
    printL(list);
    delete(1, &list);
    printL(list);

    return 0;

}