#include <stdio.h>

#define size 100

typedef struct {
    int dados[size];
    int topo;
} Pilha;

void inicializar(Pilha *p){
    p->topo = -1;
}

int push(Pilha *p, int x){
    if (p->topo == size - 1){
        
    }
    else{
        p->topo++;
        p->dados[p->topo] = x;
    }
    return x;
}

int pop(Pilha *p){
    int removed;
    
    if (p->topo == size - 1){
        
    }
    else {
        removed = p->dados[p->topo];
        p->topo--;
    }
    return removed;
}

int main(){
    Pilha minha_pilha;
    
    inicializar(&minha_pilha);
    push(&minha_pilha, 1);
    push(&minha_pilha, 2);
    pop(&minha_pilha);
    
    for(int i = 0; i <= minha_pilha.topo; i++){
        printf("%d ", minha_pilha.dados[i]);
    }
    return 0;
}