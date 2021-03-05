#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "avl.h"
#include "bin.h"

TNoAvl *criar(int v){
  TNoAvl *e = (TNoAvl *)malloc(sizeof(TNoAvl));
  e->altura = 0;
  e->valor = v;
  e->dir = NULL;
  e->esq = NULL;
  return e;
}

void FatorDeBalanceamento(TNoAvl *e){
    e->altura = altura(e->dir) - altura(e->esq);
    if (e->esq != NULL) FatorDeBalanceamento(e->esq);
    if (e->dir != NULL) FatorDeBalanceamento(e->dir);

}

TNoAvl *rotacaoEsq(TNoAvl *e){
    TNoAvl *ptaux1, *ptaux2;
    ptaux1 = e->esq;

    if (ptaux1->altura == -1){
       e->esq = ptaux1->dir;
       ptaux1->dir = e;
       e->altura = 0;
       ptaux1 = 0;
       return ptaux1;
    }

}
