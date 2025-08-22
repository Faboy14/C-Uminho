#include <stdio.h>

int main(){
    int numeros[100], i = 0, maior = 0, aux[100];

    printf("Numbers \n");

    //loop para pegar as entradas
    while (1) {
        scanf("%d", &numeros[i]);
        if (numeros[i] == 0) break; 
        i++;
        } //i acaba sendo o tamanho do array 

    maior = numeros[0];
    
    //loop para pegar o maior valor
    for(int j = 0; j < i; j++){
        if (numeros[j] > maior) maior = numeros[j];
    }

    int n = 0;

    //loop para preencher um array auxiliar sem o maior valor
    for(int p = 0; p<i; p++){
        if (numeros[p] != maior){ 
            aux[n] = numeros[p]; 
            n++;
        } else {
            continue;
        }
        }
    
        maior = aux[0];

        // Loop para pegar o maior elemento do array auxiliar, que e o segundo maior do array inicial
        for(i = 1; i<n;i++){
            if(aux[i] > maior) maior = aux[i];
        }
    
        printf("O segundo maior elemento e %d", maior);
    
}


