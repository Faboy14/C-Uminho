#include <stdio.h>

int main(){
    unsigned int valor = 0;
    int i = 0, bin[100];

    scanf("%d", &valor);

    //calculo de seu valor binario (ao contrario)

    for(i = 0; ; i++){
        if(valor < 2) {
            bin[i] = valor;
            break;
        } else {
        bin[i] = valor % 2; 
        valor /= 2;
        }
    }

    //contar numeros 1
    int ones = 0;

    for(int j = 0; j < i + 1; j++){
        if(bin[j] == 1) ones++;
    }
    printf("A quantidade de uns e %d", ones);
}