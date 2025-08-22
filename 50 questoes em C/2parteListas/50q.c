#include <stdio.h>
#include <stdlib.h>
#include "50q.h"

int length(LInt q){
    int count = 0;

    if(q == NULL){
        return 0; // verifica se a lista e vazia
    }
    else
    {
        LInt aux = q; //inicializa o ponteiro auxiliar para percorrer a lista, assimm nao perco o ponteiro para o no iniicial
        while(aux != NULL){
            count++;   // atualizo o contador
            aux = aux->prox;  //aux passa a ser o proximo no
        }
    }
    return count;
}

void printaL(LInt q){

    if(q == NULL)
        return;
    else
    {
    LInt aux = q;
    while (aux != NULL){
        printf("[%d] -> ", aux->valor); 
        aux = aux->prox;
    }
    printf("NULL");
}
}

void freeL(LInt q){

    if(q == NULL){
        return;
    }
    else 
    {
         while(q != NULL){
            LInt next = q->prox;
            free(q);
            q = next;
         }
    }
    return;
}

void insertOrd (LInt *q, int x){

    LInt newNode = malloc(sizeof(struct lligada));
    newNode->valor = x;

    if(*q == NULL){
        *q = newNode; // se é uma lista vazia, insere o no e ele passa a ser a lista
        newNode->prox = NULL;
    }
    else if ((*q)->valor > x)
    {
        newNode->prox = *q;
        *q = newNode;
    }
    else 
    {
        LInt aux = *q;
        while(aux->prox != NULL && aux->prox->valor < x){ //percorro a lista ate o proximo no ser maior que o valor que quero insererir ou ele ser nulo
            aux = aux->prox;
        } //ao parar o loop, siginifica que achei a posição a ser inserida
        newNode->prox = aux->prox; // o proximo no novo no é o proximo do atual    novo -> atua->prox
        aux->prox = newNode;  // o proximo do atual sera o novo no    atual -> novo -> atual -> prox
    }
}

void inverte(LInt *q){

    if(*q == NULL){
        return;
    }

    LInt previous = NULL;
    LInt current = *q;
    LInt next;

    while(current != NULL){
        next = current->prox; //salvo o proximo valor que irei para apos o fim do loop
        current->prox = previous; // o no atual apontara para o seu anterior, invertendo a ordem
        previous = current; // o anterior passa a ser o atual
        current = next; // o atual passa a ser o proximo
    }

    *q = previous; // o loop para em previous, onde começa a nova lista
}

int removeOneOrd (LInt *q, int x){
    if(*q == NULL){
        return 1;
    }
    else if((*q)->prox == NULL)
    {
        q = NULL;
        return 0;
    }
    else
    {
        LInt current = *q;
        LInt previous = NULL;

        while(current != NULL && current->valor != x)
        {
            previous = current;
            current = current->prox;
        }

        if(current->valor != x && current->prox == NULL){
            return 1;
        }
        else 
        {
            previous->prox = current->prox;
            current->prox = NULL;
            free(current);
        }
    }
    return 0;
        
}

//Defina uma fun¸c˜ao LLig parteAmeio (LLig *l) que, parte uma lista n˜ao vazia *l a meio.
//Se x contiver os elementos 1,2,3,4,5, ap´os a invoca¸c˜ao y=parteAmeio(&x) a lista y dever´a
//conter os elementos 1,2 e a lista x os restantes 3,4,5

//construir uma nova lista com os n elementos de x
// retirar n elementos de x
//retornar a lista construida

LInt parteAmeio (LInt *l)
{     
    LInt current = *l;
    LInt head = *l;
    LInt previous = NULL;
    int l_length = length(*l)/2;
    if (*l == NULL)
    {
        return NULL;
    } 
    else if ((*l)->prox == NULL) 
    {
        free(*l);
        return head;
    } 
    else 
    {
        while (l_length >= 0)
        {   
            previous = current;
            current = current->prox;
            l_length--;
        }
        if (previous != NULL) previous->prox = NULL;
        *l = current;
    }
    return head;
}


LInt parteAmeio2 (LInt *l)
{   
    LInt n_list = *l;
    if (*l == NULL) return NULL;
    else if ((*l)->prox == NULL)
    {
        n_list = NULL;
        return n_list;
    }
    else
    {   
        LInt aux = n_list;
        int n_length = length(*l)/2;
        while (n_length >= 0)
        {
            aux = aux->prox;
            n_length--;
        }
        *l = aux->prox;
        aux->prox = NULL;
    }
    return n_list;
}

//Apresente uma defini¸c˜ao n˜ao recursiva da fun¸c˜ao int removeAll (LInt *, int) que remove
//todas as ocorrˆencias de um dado inteiro de uma lista, retornando o n´umero de c´elulas removi-
//das

int removeAll (LInt *l, int x)
{   
    int counter = 0;
    LInt previous = NULL;
    LInt current = *l;
    LInt next;
    LInt temp = NULL;

    if (*l == NULL)
    {
        return 0;
    }
    else if ((*l)->prox == NULL)
    {
        if ((*l)->valor == x)
        {
            *l = NULL;
            counter++;
        }
        return counter;
    } 
    else
    {
        while(current != NULL)
        {
            if (current->valor == x)
            {
                if (previous == NULL) // if the found number is the first of the list: 
                {                  
                    *l = current->prox;  // I need to switch the initial pointer to the next node
                    temp = current;     //uses temp to free the current node
                    current = current->prox;  //updates the current pointer
                    free(temp);
                    counter++;    // 1 more for the removed count
                }
                else        //if it is not the first of the list, I just remove it normally
                {
                next = current->prox;              //use next to not lost the next node
                previous->prox = current->prox;    // now I remove all the connections with the node to be removed
                current->prox = NULL;
                temp = current;
                free(temp);   //free the current node
                current = next; // updates current to continue the iteration with the next node
                counter++;
                }
            }
            else        //if I don't find x, just keeps going deep in list
            {
            previous = current; 
            current = current->prox;
            }
        }
    }
    return counter;
}

//Defina uma fun¸c˜ao void merge (LInt *r, LInt a, LInt b) que junta duas listas orde-
//nadas (a e b) numa ´unica lista ordenada (*r).

void merge (LInt *r, LInt a, LInt b)
{   

    if(a == NULL && b == NULL) *r = NULL;
    else if (a == NULL) *r = b;
    else if (b == NULL) *r = a;
    else
    {
    while (a && b)
    {
        if (a->valor < b->valor)
        {
            *r = a;
             a = a->prox;
        }
        else
        {
            *r = b;
            b = b->prox;
            
        }
        r = &(*r)->prox;
    }
    }
    if (a != NULL) *r = a;
    else *r = b;
}

void splitQS (LInt l, int x, LInt *mx, LInt *Mx)
{
    LInt *pmx = mx, *pMx = Mx;
    while (l) {
        if (l->valor < x) {
            *pmx = l;
            pmx = &((*pmx)->prox);
        } else {
            *pMx = l;
            pMx = &((*pMx)->prox);
        }
        l = l->prox;
    }
    *pmx = NULL;
    *pMx = NULL;
}

int removeDups (LInt *l)
{   
    LInt previous = NULL;
    LInt current = *l;
    if (*l == NULL) return -1;
    else
    {
        while (current != NULL){ // an external loop that runs through the whole list, only one time
            LInt verifier = current->prox; // verifier used to compare elements, start as next node of current
            previous = current;             //previous starts as current node, he will be used in the removal process
            while (verifier != NULL)  // an internal loop that run the list several times, to compare the current element with the rest of list
            {
                if (verifier->valor == current->valor)
                {
                    LInt next = verifier->prox;         // saves the next element to be compared
                    previous->prox = next;          //previous removes its link to the duplicated node
                    verifier->prox = NULL;          // removes the duplicated node next link
                    verifier = next;                    // verifier is now the next value of the removed node
                }
                else                         
                {
                    previous = verifier; //advances previous pointer
                    verifier = verifier->prox; // advances the verifier
                }
            }
            current = current->prox;   //when checker all nodes for the current values, can pick another node to start comparing again
        }
    }
    return 0;
}

 void concatL (LInt *a, LInt b)
 {
    if(*a == NULL)
    {
        *a = b;
    }
    else
    {
        LInt current = *a;
        while (current->prox != NULL) // why current->prox and not current
        {
            current = current->prox;
        }
        current->prox = b;
    }
 }