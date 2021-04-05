#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "avl.h"
#include "b.h"

int main(){
    srand(time(NULL));
    

    int avl_pior_caso[5];
    int avl_melhor_caso[5];

    
    ArvoreB* arvore = criaArvore(1);
    adicionaChave(arvore, 12);
    adicionaChave(arvore, 3);
    adicionaChave(arvore, 5);
    adicionaChave(arvore, 7);
    adicionaChave(arvore, 15);
    adicionaChave(arvore, 99);
    adicionaChave(arvore, 1);

    percorreArvore(arvore->raiz);

    printf("\nNumero de operacoes %d\n", contadorB);
}