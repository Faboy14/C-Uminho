#include <stdio.h>
#include <stdlib.h>

int pesquisa(int x, int a[], int N){

    int m;

    if(m == 0){
        return -1;
    }

    m = N / 2;

    if(a[m] == x) return 0;
    else if(a[m] > x)
        pesquisa(x, a, m-1);
    else pesquisa(x, a[m+1], )
}