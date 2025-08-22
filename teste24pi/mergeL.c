#include <stdio.h>
#include <stdlib.h>

typedef struct lint_nodo {
int valor;
struct lint_nodo *prox;
} *LInt;

void merge(LInt *r, LInt a, LInt b){
    
    if(a == NULL && b == NULL) exit(-1);
    else if(a == NULL){
        *r = b;
        return;
    }
    else if(b == NULL){
        *r = a;
        return;
    }
    else
    {   
        LInt *aux = r
        while(a->prox != NULL && b->prox != NULL){
            if(a->valor < b->valor){
                
            }
        }
    }
}

int main(){

    LInt n1 = malloc(sizeof(struct lint_nodo));
    LInt n2 = malloc(sizeof(struct lint_nodo));
    //LInt n3 = malloc(sizeof(struct lint_nodo));

    // Atribuindo valores
    n1->valor = 10;
    n2->valor = 20;
    //n3->valor = 30;

    // Ligando os nós
    n1->prox = n2;
    n2->prox = NULL;
    //n3->prox = NULL;

    

    while (temp != NULL) {

        printf("%d -> ", temp->valor);
        temp = temp->prox;
    }
    printf("NULL\n");
}
}