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

    /*
    for(int i=0;i < 40;i++){
        adicionaChave(arvore,rand_array[i]);
    }
    */
    
    ArvoreB* arvore1 = criaArvore(1);    
    adicionaChave(arvore1, 235);
    adicionaChave(arvore1, 209);
    adicionaChave(arvore1, 190);
    adicionaChave(arvore1, 181);
    adicionaChave(arvore1, 153);
    adicionaChave(arvore1, 120);
    adicionaChave(arvore1, 114);
    adicionaChave(arvore1, 104);
    adicionaChave(arvore1, 99);
    adicionaChave(arvore1, 94);
    adicionaChave(arvore1, 15);
    adicionaChave(arvore1, 12);
    adicionaChave(arvore1, 7);
    adicionaChave(arvore1, 5);
    adicionaChave(arvore1, 3);
    adicionaChave(arvore1, 1);
    percorreArvore(arvore1->raiz);
    printf("\nNumero de operacoes %d\n", contadorB);
    contadorB=0;

    ArvoreB* arvore2 = criaArvore(1);
    adicionaChave(arvore2, 1);
    adicionaChave(arvore2, 3);
    adicionaChave(arvore2, 5);
    adicionaChave(arvore2, 7);
    adicionaChave(arvore2, 12);
    adicionaChave(arvore2, 15);
    adicionaChave(arvore2, 94);
    adicionaChave(arvore2, 99);
    adicionaChave(arvore2, 104);
    adicionaChave(arvore2, 114);
    adicionaChave(arvore2, 120);
    adicionaChave(arvore2, 153);
    adicionaChave(arvore2, 181);
    adicionaChave(arvore2, 190);
    adicionaChave(arvore2, 209);
    adicionaChave(arvore2, 235);
    
    percorreArvore(arvore2->raiz);

    printf("\nNumero de operacoes %d\n", contadorB);
}