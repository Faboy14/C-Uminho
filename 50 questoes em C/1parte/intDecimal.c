#include <stdio.h>

int main(){
    int valor = 0, i, count = 0;

    printf("N: \n");
    scanf("%d", &valor);

    for(i = 1; ; i = i*10){
        if(valor >= i){
        count++;
        } else {
        break;
        }
    }
    printf("O numero de digitos necessarios para escrever %d e %d", valor, count);
}