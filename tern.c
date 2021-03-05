#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "tern.h"

TNoN *criarN(int v, int q){
  TNoN *e;
  int i;
  e = (TNoN *)malloc(sizeof(TNoN));
  e->qtde = q;
  e->valor = v;

  if (q > 0)
    e->filhos = (TNoN **)malloc(q * sizeof(TNoN *));

  else
    e->filhos = NULL;

  for (i = 0; i < q; i++)
    e->filhos[i] = NULL;
  
  return e;
}

void exibeNoN(TNoN *e){
  printf("%d ", e->valor);
}

void preordemN(TNoN *e){
  exibeNoN(e);
  int i;
  
  for (i = 0; i < e->qtde; i++)
    if (e->filhos[i] != NULL)
      preordemN(e->filhos[i]);
  
}

void simetricaN(TNoN *e){
  int i;
  for (i = 0; i < e->qtde / 2; i++){
    if (e->filhos[i] != NULL)
      posordemN(e->filhos[i]);
  }
  exibeNoN(e);
  for (i = e->qtde / 2; i < e->qtde; i++){
    if (e->filhos[i] != NULL)
      posordemN(e->filhos[i]);
  }
}

void posordemN(TNoN *e){
  int i;
  for (i = 0; i < e->qtde; i++){
    if (e->filhos[i] != NULL)
      posordemN(e->filhos[i]);
  }
  exibeNoN(e);
}

int somaN(TNoN *e){
  int i, s = 0;
  for (i = 0; i < e->qtde; i++){
    if (e->filhos[i] != NULL)
      s += somaN(e->filhos[i]);
  }
  return s + e->valor;
}

void substituiValorVetorN(TNoN *e, int n){
  int i;
  e->valor = n;
  for(i = 0; i < e->qtde; i++){
    if (e->filhos[i] != NULL){
     substituiValorVetorN(e->filhos[i], n); 
    }
  }
}


int alturaN(TNoN *e){
  int i, alt = 0;
  for (i = 0; i < e->qtde; i++){
    int a = 0;
    if (e->filhos[i] != NULL)
      a = alturaN(e->filhos[i]);
    if (a > alt)
      alt = a;
  }
  return alt + 1;
}

void constroiBin(TNoN *e){ //Ternario para binario
  int i;
  for (i = 0; i < e->qtde; i++){
    if (e->filhos[i] != NULL){
      constroiBin(e->filhos[i]);
      if (i != e->qtde - 1){
        TNoN *no = e->filhos[i];
        TNoN **novoFilhos = (TNoN **)malloc((no->qtde + 1) * sizeof(TNoN *));
        int j;
        for (j = 0; j < no->qtde; j++){
          novoFilhos[j] = no->filhos[j];
        }
        novoFilhos[no->qtde] = e->filhos[i + 1];
        no->qtde = no->qtde + 1;
        no->filhos = novoFilhos;
      }
      if (i > 0)
        e->filhos[i] = NULL;
    }
  }
}

