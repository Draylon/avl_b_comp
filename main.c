#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "avl.h"
#include "b_tree.c"
#define SAMPLING 1
#define RANGE 100

int* random_array(const int size,const int order){
    int* rand_array = malloc(sizeof(int)*size);
    int ii=0;
    while(ii < size){
        int r_int = rand() % 200; // numeros de 0 a 100

        int match=0; // BOOL
        for(int iic=0;iic < ii;iic++){
            if(order == 0) // Totalmente aleatório
                if(rand_array[iic] == r_int){match=1;break;}
            else if(order ==1) // Crescente
                if(rand_array[iic] <= r_int){match=1;break;}
            else if(order ==-1) // Decrescente
                if(rand_array[iic] >= r_int){match=1;break;}
        }
        if(match==0){
            rand_array[ii] = r_int;
            ii++;
        }else
            continue;
    }
    /*for(int iasd=0;iasd < size;iasd++){
        printf("%d ",rand_array[iasd]);
    }
    printf("\nfeito\n");*/
    return rand_array;
}

int main(){
    srand(time(NULL));

    /*ArvoreAvl* a1 = criar();
    int* rand_asd = random_array(100,0);
    for(int i=0;i < 100;i++){
        adicionar(a1,rand_asd[i]);
        printf("\nNumero de operacoes %d\n",contadorAvl);
    }
    for (int i = 0; i < 50; i++) {
        adicionar(a1,i); 
        adicionar(a1,99-i);  
    }
    printf("altura %d\n",altura(a1->raiz));
    percorrerProfundidadeInOrder(a1->raiz,visitar);
    printf("\nNumero de operacoes %d\n\n",contadorAvl);
    freeAvl(a1);*/
    //free(rand_asd);

    for(int i = 1;i <= RANGE;i++){
        
        int rand_avl = 0,rand_b = 0;
        for(int it=0;it < SAMPLING;it++){
            ArvoreAvl* a1_rand = criar();
            //ArvoreB* a2_rand = criaArvore(1);
            int* rand_noorder = random_array(i,0);
            //printf("rand\n");
            for(int ii=0; ii < i;ii++){
                //printf("%d ",rand_noorder[ii]);
                adicionar(a1_rand,rand_noorder[ii]);
                //adicionaChave(a2_rand,rand_noorder[ii]);
            }
            //printf("\nperc\n");
            printOrder(a1_rand->raiz);
            //printf("\n\n");
            //percorreArvore(a2_rand->raiz);
            //printf("\nRand %d %d\n\n",contadorAvl, contadorB);
            rand_avl+=contadorAvl;
            //rand_b+=contadorB;
            //printf("%d ",contadorAvl);
            contadorAvl=0;
            //contadorB=0;
            freeAvl(a1_rand);
            //freeB(a2_rand);
            free(rand_noorder);
        }
        printf("\n");
        rand_avl = (int)(rand_avl/SAMPLING);
        rand_b = (int)(rand_b/SAMPLING);
        
        //printf(" | %d ",rand_avl);
        printf("%d %d ",i,rand_avl);
        
        //====================

        ArvoreAvl* a1_asc = criar();
        ArvoreAvl* a1_desc = criar();
        //ArvoreB* a2_asc = criaArvore(1);
        //ArvoreB* a2_desc = criaArvore(1);

        int* rand_asc = random_array(i,1);
        int* rand_desc = random_array(i,-1);

        for(int ii=0; ii < i;ii++){
            adicionar(a1_asc,rand_asc[ii]);
            //adicionaChave(a2_asc,rand_asc[ii]);
        }
        //printOrder(a1_asc->raiz);
        //percorreArvore(a2_asc->raiz);
        //printf("\nAsc %d %d\n\n",contadorAvl, contadorB);
        
        printf("%d %d ",i,contadorAvl);

        contadorAvl=0;
        //contadorB=0;
        //====================
        for(int ii=0; ii < i;ii++){
            adicionar(a1_desc,rand_desc[ii]);
            //adicionaChave(a2_desc,rand_desc[ii]);
        }
        //printOrder(a1_desc->raiz);
        //percorreArvore(a2_desc->raiz);
        //printf("\nDesc %d %d\n\n",contadorAvl, contadorB);
        printf("%d\n",contadorAvl);
        contadorAvl=0;
        //contadorB=0;

        freeAvl(a1_asc);
        freeAvl(a1_desc);
        //freeB(a2_asc);
        //freeB(a2_desc);
        free(rand_asc);
        free(rand_desc);
        
        //printf("\n||%d %d %d||\n",grafico_avl[0][0],grafico_avl[0][1],grafico_avl[0][2]);
    }

    /*
    * B TREE
    */
    ArvoreB* tree = criar();
 
    int *array = random_array(100, 0);

    for(int iasd=0;iasd < 100;iasd++){
        printf("%d ",array[iasd]);
    }
    printf("\n");

    // int array[100] = {62,44,60,84,23,21,1,50,43,88,56,86,61,80,35,0,18,38,16,97,70,59,98,36,66,19,63,28,15,75,65,90,49,93,92,6,55,68,51,41,67,89,85,83,58,7,11,52,3,34,2,5,39,77,24,45,30,9,79,78,4,10,8,14,94,12,33,53,73,42,74,20,29,26,54,17,27,25,64,48,81,96,22,47,37,13,57,99,31,69,32,71,76,87,40,82,95,46,91,72};

    for (int i = 0; i < 100; i++) {
        adicionar(tree,array[i]);  
    }

    printf("Altura : %d\n", altura(tree->raiz));
    printf("Total operações: %d\n", count_total_op);
    remover(tree, tree->raiz);


    /*for(int i=0;i < 5;i++){
        for(int j=0;j < 3;j++){
            printf("%d ",grafico_avl[i][j]);
        }
        printf("\n");
    }*/
    
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
    
    /*ArvoreAvl* arvore1 = criar();
    adicionar(arvore1, 235);
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
    percorrerProfundidadeInOrder(arvore1->raiz,visitar);
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

    printf("\nNumero de operacoes %d\n", contadorAvl);*/
}
