#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *prox;
} No;

void addbeggining(No **lista, int num){

    No *novo = (No *) malloc(sizeof(No));
    novo->valor = num;

    if (!novo){

    }

    novo->prox = *lista;
    *lista = novo;

}

void append(No **lista, int num) {
    // 1. Cria o nó novo
    No *novo = malloc(sizeof(No));
    if (!novo) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    novo->valor = num;
    novo->prox  = NULL;

    // 2. Se a lista está vazia, insere como cabeça
    if (*lista == NULL) {
        *lista = novo;
        return;
    }

    // 3. Caso contrário, percorre até o último nó
    No *atual = *lista;
    while (atual->prox != NULL) {
        atual = atual->prox;
    }
    // 4. Liga o último nó ao novo
    atual->prox = novo;

    // Não liberamos nenhum nó aqui!
}

int main(){

    No *lista = NULL;

    addbeggining(&lista, 5);
    append(&lista, 10);

    printf("%d -->", lista->valor);
    printf("%d", lista->prox->valor);
}