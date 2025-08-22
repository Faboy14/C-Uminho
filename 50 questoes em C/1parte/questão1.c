// achando o maior número de um vetor
// declarar o vetor e as variaveis
// pegar 10 numeros do usuario utilizando scanf junto ao loop for
// numeros[i] -> preenche todos os indices do vetor
// uso o primeiro indice do vetor para ser modelo de comparação com os outros valores
// se o valor numeros[i] é maior que o maior valor até entao, ele passa a ocupar a variavel "maior" 
// Loop continua e no final printa quem ficou como maior

#include <stdio.h>
#include <stdlib.h>

int main() {
    int numeros[100];
    int i = 0, j;
    int maior;

    printf("Digite vários números com o último sendo 0:\n");

    // Lê números até o usuário digitar 0
    do {
        scanf("%d", &numeros[i]);
    } while (numeros[i++] != 0); // Incrementa `i` após cada leitura

    maior = numeros[0]; // Inicializa `maior` com o primeiro número

    // Encontra o maior número (ignora o último elemento, que é 0)
    for (j = 1; j < i - 1; j++) { // `i - 1` para ignorar o 0 final
        if (numeros[j] > maior) {
            maior = numeros[j];
        }
    }

    printf("O maior número da sequência é: %d\n", maior);

    return 0;
}
