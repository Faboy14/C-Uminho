#include <stdio.h>
#include <stdlib.h>

typedef struct lint_nodo {
int valor;
struct lint_nodo *prox;
} *LInt;

void duplicaLista(LInt l){

    if(l == NULL)
        exit(-1);
    else{
        LInt aux = l;   //variavel para percorrer a lista
        while(aux->prox != NULL){ 
            LInt newNode = malloc(sizeof(struct lint_nodo));   //aloco memoria para o novo no
            newNode->valor = aux->valor;                // duplico o valor do no atual 
            LInt next;                                      //crio uma variavel para salvar o proximo no que nao e repetido
            next = aux->prox;                             // atribuo ela o valor do proximo no nao repetido, que é o proximo do atual
            aux->prox = newNode;                        // o proximo do atual passa ser o novo no (com valor duplicado)
            newNode->prox = next;                       // o proximo do novo no passa ser o proximo valor (nao duplicado)
            aux = next;                                // o atual passa a ser o next, no que eu havia salvo o proximo no nao repetido
        }        
        LInt newNode = malloc(sizeof(struct lint_nodo));    //o loop para no ultimo no, mas nao o duplica
        newNode->valor = aux->valor;                //para isso, duplico manualmente apos o no
        newNode->prox = NULL;
        aux->prox = newNode;          
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

    // Agora n1 é o início da lista
    LInt lista = n1;

    duplicaLista(lista);

    LInt temp = lista;
    while (temp != NULL) {

        printf("%d -> ", temp->valor);
        temp = temp->prox;
    }
    printf("NULL\n");
}
