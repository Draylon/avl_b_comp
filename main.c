#include <stdio.h>
#include <time.h>
#include <stdlib.h>
//#include "avl.h"
#include "b.h"

int* random_array(const int size){
    int* rand_array = malloc(sizeof(int)*size);
    int ii=0;
    while(ii < size){
        int r_int = rand();

        int match=0; // BOOL
        for(int iic=0;iic < ii;iic++){
            if(rand_array[iic] == r_int)
                match=1;
                break;
        }
        if(match==0){
            rand_array[ii] = r_int;
            ii++;
        }else
            continue;
    }
    return rand_array;
}

int main(){
    srand(time(NULL));
    

    int* rand_array = random_array(40);
    /*for(int iitt=0;iitt<5;iitt++){
        for(int iit=0;iit < 8;iit++){
            printf("%d ",rand_array[iit+8*iitt]);
        }
        printf("\n");
    }*/

    ArvoreB* arvore = criaArvore(1);
    for(int i=0;i < 40;i++){
        adicionaChave(arvore,rand_array[i]);
    }
    percorreArvore(arvore->raiz);
    printf("\nNumero de operacoes %d\n", contadorB);
    
    /*ArvoreB* arvore = criaArvore(1);
    adicionaChave(arvore, 12);
    adicionaChave(arvore, 3);
    adicionaChave(arvore, 5);
    adicionaChave(arvore, 7);
    adicionaChave(arvore, 15);
    adicionaChave(arvore, 99);
    adicionaChave(arvore, 1);
    adicionaChave(arvore, 94);

    percorreArvore(arvore->raiz);

    printf("\nNumero de operacoes %d\n", contadorB);*/
}