#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "bin.h"
#include "tern.h"


int main(int argc, char const *argv[]){
    TNo *raiz  = criar(501);
    int i, k[8]  = {20, 36, 12, 47, 30, 8, 10, 13};
    
    for (i = 1; i < 1001; i++){
        fflush(stdin);
        //scanf("%d",&k[i]);
        inserir(raiz, i);
    }
    printf("\n");
    
    

    //exibeNo(BuscaNaoRec(raiz, 32));
    //int x = 0;
    //x = QtdBuscaDir(raiz, 13);
    //printf("%d", x);
    printf("\n");
    //raiz->dir = criar(60);
    //printf("%d", somaImpar(raiz));
    //inserir(raiz, 60);
    //removerNo(raiz, 36);
    //removerNo(raiz, 20);
    //printf("\nmaior: %d\n", busca_maior(raiz) );
    //exibeNo(busca(raiz, 5));
    preordem(raiz);
    printf("\n");
    printf("\n");
    simetrica(raiz);
    printf("\naltura : %d", altura(raiz));
    
    printf("\n");
    //posordem(raiz);
    //exibeNo(raiz);
    //exibeNo(raiz->esq);
    //exibeNo(raiz->dir);
    //TNoN *raizN;
    //raizN = criarN(10, 4);
    //raizN->filhos[0] = criarN(15, 2);
    //exibeNoN(raizN);
    //exibeNoN(raizN->filhos[0]);
    //liberaBin(raiz);

    return 0;
}