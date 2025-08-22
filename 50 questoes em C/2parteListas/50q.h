#ifndef _50Q_H_
#define _50Q_H_

typedef struct lligada {
    int valor;
    struct lligada *prox;
} *LInt;

void inverte(LInt *q);
int length(LInt q);
void freeL(LInt q);
void insertOrd(LInt *q, int x);
void printaL(LInt q);
int removeOneOrd (LInt *q, int x);
LInt parteAmeio (LInt *l);
LInt parteAmeio2 (LInt *l);
int removeAll (LInt *l, int x);
void merge (LInt *r, LInt a, LInt b);
void splitQS (LInt l, int x, LInt *mx, LInt *Mx);
int removeDups (LInt *l);
void concatL (LInt *a, LInt b);

#endif // _50Q_H_