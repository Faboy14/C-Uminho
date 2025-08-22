#include <stdio.h>

int partir(int *v, int inicio, int fim){

    int pivo = (v[inicio] + v[fim] + v[(inicio + fim)/2]) / 3;

    while(inicio < fim){
        while(inicio < fim && v[inicio] <= pivo){
            inicio++;
        }
        //para quando achar um elemento maior que o pivo, no indice inicio

        while(inicio < fim && v[fim] > pivo){
            fim--;
        }

        if (inicio < fim) {
        int aux = v[inicio];
        v[inicio] = v[fim];
        v[fim] = aux;
        }
    }
    return inicio;
}

void quicksort(int *v, int inicio, int fim){
    if(inicio >=fim) return;
    int particao = partir(v, inicio, fim);
    quicksort(v, inicio, particao-1);
    quicksort(v, particao, fim);
}

int main(){
    int v[] = {8,7,6,5,4,3,2,1};

    quicksort(v, 0 , 7);

    for(int i = 0; i < 8; i++){
        printf("%d ", v[i]);
    }
    return 0;
}

// 1- achar o pivo
//2- percorrer o vetor da direita para a esquerda ate achar um vetor maior que o vetor
// 3- percorrer o vetor da esquerda para direita ate achar um valor menor que o pivo
// quando eles se encontrarem, parar o ciclo
// retornar o meio