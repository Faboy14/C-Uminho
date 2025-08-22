#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool parentesisOk(char exp[]){

    int j = 0;   // usada para medir o tamanho do array
    char aux[100];    // vetor dos parenteses

    for(int i = 0; exp[i] != '\0'; i++){
        char c = exp[i];
        if(c == '(' || c == '{' || c == '[' || c == ']' || c == '}' || c == ')'){
            aux[j] = c;   //preencho o vetor dos parenteses conforme acho-os
            j++; 
        }
    }

    int size = j - 1;     //distancia entre o elemento 0 até o ultimo elemento do array

    for(int i = 0; i < j/2; i++){ 
        if(aux[i] == '('){
            if(aux[i + size] != ')')    //verifica simetria
                return false;           //ao somar size, acho o parentes simetrico ao do indice atual
        }
        if(aux[i] == '{'){
            if(aux[i + size] != '}')
                return false;
        }
        if(aux[i] == '['){
            if(aux[i + size] != ']')
                return false;
        }
        size = size - 2;    //a cada indice avançado, a distancia entre os indices diminui
    }   
    return true;  //caso nada errado, retorna true;
}

int main(){

    char ex[] = "3 + [2 - (3 - x)] + 4";

    if(parentesisOk(ex))
        printf("Tudo ok");
    else printf("Ha parentesis errados.");

}