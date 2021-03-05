#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "bin.h"

TNo *criar(int v){
  TNo *e = (TNo *)malloc(sizeof(TNo));
  e->valor = v;
  e->dir = NULL;
  e->esq = NULL;
  return e;
}

void exibeNo(TNo *e){
  printf("%d ", e->valor);
}

int valorNo(TNo *e){
  return e->valor;
}

void preordem(TNo *e){
  exibeNo(e);
  if (e->esq != NULL)   preordem(e->esq);
  if (e->dir != NULL)   preordem(e->dir);
}

void simetrica(TNo *e){
  if (e->esq != NULL)   simetrica(e->esq);
  exibeNo(e);
  if (e->dir != NULL)   simetrica(e->dir);
}

void posordem(TNo *e){
  if (e->esq != NULL)   posordem(e->esq);
  if (e->dir != NULL)   posordem(e->dir);
  exibeNo(e);
}

int soma(TNo *e){
  int somaEsq = 0, somaDir = 0;
  if (e->esq != NULL)    somaEsq = soma(e->esq);
  if (e->dir != NULL)    somaDir = soma(e->dir);
  return somaEsq + somaDir + e->valor;
}

int altura(TNo *e){
  int altEsq = 0, altDir = 0;
  if (e->esq != NULL)    altEsq = altura(e->esq);
  if (e->dir != NULL)    altDir = altura(e->dir);
  if (altEsq > altDir)    return altEsq + 1;
  else    return altDir + 1;
}

int QtdNos(TNo *e){
  int esq = 0, dir = 0;
  if (e->dir != NULL)   dir = QtdNos(e->dir);
  if (e->esq != NULL)   esq = QtdNos(e->esq);
  return dir + esq + 1;
}

TNo *busca(TNo *e, int raiz){
  if (e == NULL || e->valor == raiz) return e;
  else if (e->valor > raiz)  return busca(e->esq, raiz);
  else if (e->valor < raiz)  return busca(e->dir, raiz);
  //return e;
}

TNo *buscaB(TNo *e, int raiz){
  if (e->valor == raiz || (raiz < e->valor && e->esq == NULL) || (raiz > e->valor && e->dir == NULL) ) return e;
  else if (e->valor > raiz)  return busca(e->esq, raiz);
  else if (e->valor < raiz)  return busca(e->dir, raiz);
  //return e;
}

TNo *BuscaNaoRec(TNo *e, int n){
    TNo *ptbuscaAux = e;
    while(ptbuscaAux != NULL && ptbuscaAux->valor != n){
        if(ptbuscaAux->valor == n || (n < ptbuscaAux->valor && ptbuscaAux->esq == NULL) || (n > ptbuscaAux->valor && ptbuscaAux->dir == NULL) ) return ptbuscaAux;
        else if(n < ptbuscaAux->valor)  ptbuscaAux = ptbuscaAux->esq;
        else  ptbuscaAux = ptbuscaAux->dir;
    }
    return NULL;
}

int QtdBuscaDir(TNo *e, int valor){
  TNo *ptaux = e;
  int x = 0;
  while(ptaux != NULL && ptaux->valor != valor){
        if(valor < ptaux->valor){
          ptaux = ptaux->esq;
        }
          
        else{
          ptaux = ptaux->dir;
          if(ptaux->valor > valor){
            x = x + 1;
            printf("\n%d\n", x);
          }
        }     
  }
  return x;
}

int somaImpar(TNo *e){
  int somaEsq = 0, somaDir = 0, k=0;
  if (e->esq != NULL)   somaEsq = somaImpar(e->esq);
  if (e->dir != NULL)   somaDir = somaImpar(e->dir);
  if (e->valor % 2 == 1)    k = e->valor;
  return k + somaDir + somaEsq;
}

TNo *inserir(TNo *e, int valor){
  if (e == NULL){
    e = criar(valor); 
    return e;
  }
  else if (valor < e->valor)  e->esq = inserir(e->esq, valor);
  else if (valor > e->valor ) e->dir = inserir(e->dir, valor);
  return e;
}

TNo *inserirIterat(TNo *e, int valor){
  TNo *novo = criar(valor);
  
  if (e == NULL){
    e = novo;
  }

  else{
    TNo *aux = e;
    TNo *ant = NULL;
    
    while (aux != NULL){
      ant = aux;
      if (valor == aux->valor){
        return aux;
      }
      if (valor > aux->valor){
        aux = aux->dir;
      }
      else{
        aux = aux->esq;
      }
    }

    if (valor > ant->valor){
      ant->dir = novo;
    }
    else{
      ant->esq = novo;
    }
  }

  return e;
}

void liberaNo(TNo *e){
  if(e == NULL)   return;
  liberaNo(e->dir);
  liberaNo(e->esq);
  free(e);
  e = NULL;
}

void liberaBin(TNo *e){
  if(e == NULL)   return;
  liberaNo(e);
  free(e);
}

int busca_maior(TNo *e){
  if(e->dir == NULL)    return e->valor;
  else    busca_maior(e->dir);
}

int busca_menor(TNo *e){
  if(e->esq == NULL)    return e->valor;  
  else    busca_menor(e->esq);  
}

TNo *MaisDir(TNo *e){
  TNo *ptdir = e;
  while (ptdir->dir != NULL)
    ptdir = ptdir->dir;
  return ptdir;
}

TNo *MaisEsq(TNo *e){
  TNo *ptesq = e;
  while (ptesq->esq != NULL)
    ptesq = ptesq->esq;
  return ptesq;
}

TNo *removerNo(TNo *e, int valor){
    TNo *aux;
    aux = criar(NULL);

    if (e == NULL)     return e; 
    else if (valor < e->valor)         e->esq = (removerNo(e->esq, valor));
    else if (valor > e->valor)         e->dir = (removerNo(e->dir, valor));
    else{ 
        if ((e->esq == NULL) && (e->dir == NULL)){
          free(e);
          e = NULL;
        }

        else if (e->esq == NULL){
          aux = e;
          e = e->dir;
          free(aux);  
        }

        else if (e->dir == NULL){
          aux = e;
          e = e->esq;
          free(aux); 
        }

        else{
            e->valor = MaisDir(e->esq)->valor;
            MaisDir(e->esq)->valor = valor;
            e->esq = removerNo(e->esq, valor);
        }
    }
    return e;
}

int comparar(TNo *e1, TNo *e2){ 
  if (e1 == NULL && e2 == NULL){
    return 1;
  }
  else if (e1 != NULL && e2 != NULL){
    return comparar(e1->esq, e2->esq)* comparar(e1->dir, e2->dir);
  }
  else if (e1 != e2){
    return 0;
  }
}

