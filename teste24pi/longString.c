#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int expande(char s[]){

    int i, k = 0, j = 0, p = 0;
    int letras[100];
    int vezes[100];
    char aux[100];
    // i = tamanho da string
    // k tamanho vetor vezes
    //j tamanho vetor letras
    //p usado para percorrer todas as letras

    for(i = 0; s[i] != '\0'; i++){    // percorro a string toda
        if(s[i] >= '0' && s[i] <= '9'){         // seleciono os numeros em formato de char
            vezes[k] = s[i] - '0';  // preencho um vetor somente com os numeros, mas trasnformados para int
            k++;
        } 
        else                // se nao for numero, e letra
        {
           letras[j] = s[i];   //preencho o vetor de letras
           j++; 
        }
    }

    j = 0;

    while(p < k){   //enquanto p for menor que o numero de letras/numeros(sao iguais porque sao pares)
        int copy = vezes[p];   //uso copy para controlar a repetição "xxxxx", copy assumira todos os valores do vetor vezes
                                // sendo resetada a cada iteração do loop externo
        while(copy != 0){  
            aux[j] = letras[p];         //preencho um vetor auxiliar com a letra do indice atual, ate copy zerar
            j++;
            copy--;
        }
        p++;   // quando copy zera, faço p+1 e assim avanõ para a proxima letra/repetições
    }
    aux[j] = '\0'; //fecho a string

    strcpy(s, aux);

    return j-1;  // j no final me da o tamanho da string
}

int main(){

    char s[] = "x4y1z3";
    int n = expande(s);

    for(int i = 0; s[i] != '\0'; i++){
        printf("%c ", s[i]);
    }
    putchar('\n');
    printf("O tamanho da string nova é %d", n); 

}