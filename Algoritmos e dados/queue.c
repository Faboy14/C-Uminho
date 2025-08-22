#include <stdio.h>

#define MAX 100

typedef struct {
    int dados[MAX];
    int frente;
    int fim;
} Fila;

void inicializar(Fila *fila){
    fila->frente = 0;
    fila->fim = 0;
}

int enqueue(Fila *fila, int x){
    if (fila->fim == MAX){
        return 1;
    }
    else{
        fila->dados[fila->fim] = x;
        fila->fim++;
    }
    return x;
}

int dequeue(Fila *fila){
    int x;
    
    if (fila->frente == fila->fim){
        return 1;
    }
    else {
        x = fila->dados[fila->frente];
        fila->frente++;
    }
    return x;
}

int main(){
    Fila mFila;
    
    inicializar(&mFila);
    enqueue(&mFila, 10);
    enqueue(&mFila, 20);
    dequeue(&mFila);
    
    printf("%d ", mFila.dados[mFila.fim - 1]);
    
    return 0;
}