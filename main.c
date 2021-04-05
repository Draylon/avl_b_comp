#include <stdio.h>
#include <time.h>
#include <stdlib.h>
//#include "avl.h"
#include "b.h"

int main(){
    srand(time(NULL));
    

    int rand_array[40];
    int ii=0;
    while(ii < 40){
        int r_int = rand();
        int match=1; // BOOL
        for(int iic=0;iic < ii;iic++){
            if(rand_array[iic] == r_int)
                break;
        }
    }

    
    ArvoreB* arvore = criaArvore(1);
    adicionaChave(arvore, 12);
    adicionaChave(arvore, 3);
    adicionaChave(arvore, 5);
    adicionaChave(arvore, 7);
    adicionaChave(arvore, 15);
    adicionaChave(arvore, 99);
    adicionaChave(arvore, 1);
    adicionaChave(arvore, 94);

    percorreArvore(arvore->raiz);

    printf("\nNumero de operacoes %d\n", contadorB);
}