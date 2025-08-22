#include "50q.h"
#include <stdio.h>
#include <stdlib.h>

int main(){

    LInt no1 = malloc (sizeof(struct lligada)); //alocar memoria para os novos nos em main
    LInt no2 = malloc (sizeof(struct lligada));
    no1->valor = 10;  //inicializar os nos
    no2->valor = 20;
    no1->prox = NULL;
    no2->prox = NULL;

    printaL(no1);  
    putchar('\n'); 
    printaL(no2);

    putchar('\n');
    putchar('\n');

    insertOrd(&no1, 1);
    insertOrd(&no1, 3);
    insertOrd(&no1, 3);
    insertOrd(&no1, 5);
    insertOrd(&no1, 7);
    insertOrd(&no1, 100);
    insertOrd(&no1, 100);
    insertOrd(&no2, 2);
    insertOrd(&no2, 4);
    insertOrd(&no2, 6);
    insertOrd(&no2, 8);

    int state = 0;
    int choice = -1;
    int continuE = -1;

    printf("list a: ");
    printaL(no1);
    putchar('\n');
    printf("list b: ");
    printaL(no2);

    putchar('\n');
    putchar('\n');

    printf("Press: \n 0 to inverte list 1. \n 1 to remove 20 \n 2 to break list in half \n 3 for merging 2 lists \n 4 for removing 100. \n 5 for removing duplicated \n 6 for concatenation lists\n");
    scanf("%d", &choice);

    switch (choice) {

    case 0: {
        inverte(&no1);
        printaL(no1);
        putchar('\n');
        break;
    }
    case 1: {
        removeOneOrd(&no2, 20);
        printaL(no1);
        putchar('\n');
        break;
    }
    case 2: {
        LInt n_list = parteAmeio2(&no1);
        printf("New list:\n");
        printaL(n_list);
        putchar('\n');
        printf("Old list remainder:\n");
        printaL(no1);
        break;
    }
    case 3: {
        LInt new_l = NULL;
        merge(&new_l, no1, no2);
        printaL(new_l);
        break;
    }
    case 4: {
        int n_rem = removeAll(&no1, 100);
        printaL(no1);
        break;
    }
    case 5: {
        removeDups(&no1);
        printaL(no1);
        break;
    }
    case 6: {
        concatL(&no1, no2);
        printaL(no1);
        break;
    }
    default: {
        break;
    }
}
putchar('\n');
printf("Press 0\n");
scanf("%d", &continuE);
system("cls");
}

