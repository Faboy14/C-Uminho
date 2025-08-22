#include <stdio.h>
#include <stdlib.h>

int fizz(int n) {
    return n % 3 == 0;
}

int buzz(int n) {
    return n % 5 == 0;
}

int fizzbuzz(int n) {

    int fb = -1;
    int b = -1;
for (int i = 0; i < n; i++) {
    if (fizz(i) && buzz(i)){
        printf("FizzBuzz\n");
        if(fb == -1) fb = i;
    }
    else if (fizz(i))
        printf("Fizz\n");
    else if (buzz(i)){
        printf("Buzz\n");
        if (b == -1 && fb != -1 && i > fb) b = i;
    }
    else
        printf("%d\n", i);
}

int linhas;
if(fb > b)
    linhas = fb - b;
else linhas = b - fb;

return linhas;
}

int main(){

    int linhas = fizzbuzz(15);
    printf("linhas: %d", linhas);
}