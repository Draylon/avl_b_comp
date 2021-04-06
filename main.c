#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "avl.h"
//#include "b.h"

int* random_array(const int size,const int order){
    int* rand_array = malloc(sizeof(int)*size);
    int ii=0;
    while(ii < size){
        int r_int = rand();

        int match=0; // BOOL
        for(int iic=0;iic < ii;iic++){
            if(order == 0)
                if(rand_array[iic] == r_int){match=1;break;}
            else if(order ==1)
                if(rand_array[iic] <= r_int){match=1;break;}
            else if(order ==-1)
                if(rand_array[iic] >= r_int){match=1;break;}
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
    

    int* rand_noorder = random_array(40,0);
    int* rand_asc = random_array(40,1);
    int* rand_desc = random_array(40,-1);
    /*for(int iitt=0;iitt<5;iitt++){
        for(int iit=0;iit < 8;iit++){
            printf("%d ",rand_array[iit+8*iitt]);
        }
        printf("\n");
    }*/

    /*ArvoreAvl* arvore1A=criar();
    ArvoreB* arvore1B = criaArvore(1);
    ArvoreAvl* arvore2A=criar();
    ArvoreB* arvore2B = criaArvore(1);
    ArvoreAvl* arvore3A = criar();
    ArvoreB* arvore3B = criaArvore(1);
    for(int i=0;i < 40;i++){
        adicionar(arvore1A,rand_asc[i]);
        adicionaChave(arvore1B,rand_asc[i]);
    }
    percorrerProfundidadeInOrder(arvore1A->raiz,visitar);
    percorreArvore(arvore1B->raiz);
    printf("\nNumero de operacoes %d %d\n\n",contadorAvl, contadorB);
    contadorAvl=0;
    contadorB=0;

    for(int i=0;i < 40;i++){
        adicionar(arvore2A,rand_desc[i]);
        adicionaChave(arvore2B,rand_desc[i]);
    }
    percorrerProfundidadeInOrder(arvore2A->raiz,visitar);
    percorreArvore(arvore2B->raiz);
    printf("\nNumero de operacoes %d %d\n\n",contadorAvl, contadorB);
    contadorAvl=0;
    contadorB=0;
    
    for(int i=0;i < 40;i++){
        adicionar(arvore3A,rand_noorder[i]);
        adicionaChave(arvore3B,rand_noorder[i]);
    }
    percorrerProfundidadeInOrder(arvore3A->raiz,visitar);
    percorreArvore(arvore3B->raiz);
    printf("\nNumero de operacoes %d %d\n\n",contadorAvl, contadorB);
    contadorAvl=0;
    contadorB=0;*/
    
    ArvoreAvl* arvore1 = criar();
    adicionar(arvore1, 235);
    printf("-- %d\n",arvore1->raiz->valor);
    adicionar(arvore1, 209);
    adicionar(arvore1, 190);
    adicionar(arvore1, 181);
    adicionar(arvore1, 153);
    adicionar(arvore1, 120);
    adicionar(arvore1, 114);
    adicionar(arvore1, 104);
    adicionar(arvore1, 99);
    adicionar(arvore1, 94);
    adicionar(arvore1, 15);
    adicionar(arvore1, 12);
    adicionar(arvore1, 7);
    adicionar(arvore1, 5);
    adicionar(arvore1, 3);
    adicionar(arvore1, 1);
    percorreArvore(arvore1->raiz);
    printf("\nNumero de operacoes %d\n", contadorAvl);
    contadorAvl=0;

    ArvoreAvl* arvore2 =criar();
    adicionar(arvore2, 1);
    adicionar(arvore2, 3);
    adicionar(arvore2, 5);
    adicionar(arvore2, 7);
    adicionar(arvore2, 12);
    adicionar(arvore2, 15);
    adicionar(arvore2, 94);
    adicionar(arvore2, 99);
    adicionar(arvore2, 104);
    adicionar(arvore2, 114);
    adicionar(arvore2, 120);
    adicionar(arvore2, 153);
    adicionar(arvore2, 181);
    adicionar(arvore2, 190);
    adicionar(arvore2, 209);
    adicionar(arvore2, 235);
    
    percorreArvore(arvore2->raiz);

    printf("\nNumero de operacoes %d\n", contadorAvl);
}