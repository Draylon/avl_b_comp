#include <stdio.h>
#include <stdlib.h>
#include "b.h"

contadorB=0;


ArvoreB* criaArvore(int ordem) {
    ArvoreB* a = malloc(sizeof(ArvoreB));
    a->ordem = ordem;
    a->raiz = criaNo(a);

    return a;
}

BNode* criaNo(ArvoreB* arvore) {
    int max = arvore->ordem * 2;
    BNode* no = malloc(sizeof(BNode));

    no->pai = NULL;
        
    no->chaves = malloc(sizeof(int) * (max + 1));
    no->filhos = malloc(sizeof(BNode) * (max + 2));
    no->total = 0;

    for (int i = 0; i < max + 2; i++)
        no->filhos[i] = NULL;

    return no;
}

void percorreArvore(BNode* no) {
    if (no != NULL) {
        for (int i = 0; i < no->total; i++){
            percorreArvore(no->filhos[i]); //visita o filho a esquerda
            
            printf("%d ",no->chaves[i]);
        }

        percorreArvore(no->filhos[no->total]); //visita ultimo filho (direita)
    }
}

int pesquisaBinaria(BNode* no, int chave) {
    int inicio = 0, fim = no->total - 1, meio;		
    
    while (inicio <= fim) {	
        contadorB++;
        
        meio = (inicio + fim) / 2;
        
        if (no->chaves[meio] == chave) {	
		    return meio; //encontrou	
        } else if (no->chaves[meio] > chave) {
                fim	= meio - 1;	
        } else {
            inicio = meio + 1;
        }
    }
    return inicio; //não encontrou	
}

int localizaChave(ArvoreB* arvore, int chave) {	
    BNode *no = arvore->raiz;
    
    while (no != NULL) {
        int i = pesquisaBinaria(no, chave);

        if (i < no->total && no->chaves[i] == chave) {
            return 1; //encontrou
        } else {
            no = no->filhos[i];
        }
    }

    return 0; //não encontrou	
}

BNode* localizaNo(ArvoreB* arvore, int chave) {	
    BNode *no = arvore->raiz;
    
    while (no != NULL) {
        contadorB++;

        int i = pesquisaBinaria(no, chave);

        if (no->filhos[i] == NULL)
            return no; //encontrou nó
        else
            no = no->filhos[i];
    }

    return NULL; //não encontrou nenhum nó
}

void adicionaChaveNo(BNode* no, BNode* novo, int chave) {
    int i = pesquisaBinaria(no, chave);
    
    contadorB++;

    for (int j = no->total - 1; j >= i; j--) {
        no->chaves[j + 1] = no->chaves[j];
        no->filhos[j + 2] = no->filhos[j + 1];
    }
    
    no->chaves[i] = chave;
    no->filhos[i + 1] = novo;

    no->total++;
}

int transbordo(ArvoreB* arvore, BNode* no) {
    contadorB++;
    return no->total > arvore->ordem * 2;
}

BNode* divideNo(ArvoreB* arvore, BNode* no) {
    int meio = no->total / 2;
    BNode* novo = criaNo(arvore);
    novo->pai = no->pai;

    contadorB++;
    
    for (int i = meio + 1; i < no->total; i++) {
        novo->filhos[novo->total] = no->filhos[i];
        novo->chaves[novo->total] = no->chaves[i];
        if (novo->filhos[novo->total] != NULL) novo->filhos[novo->total]->pai = novo;
        
        novo->total++;
    }

    novo->filhos[novo->total] = no->filhos[no->total];
    if (novo->filhos[novo->total] != NULL) novo->filhos[novo->total]->pai = novo;    
    no->total = meio;
    return novo;
}

void adicionaChaveRecursivo(ArvoreB* arvore, BNode* no, BNode* novo, int chave) {
    contadorB++;
    
    adicionaChaveNo(no, novo, chave);
    
    if (transbordo(arvore, no)) {
        int promovido = no->chaves[arvore->ordem]; 
        BNode* novo = divideNo(arvore, no);

        if (no->pai == NULL) {
            contadorB++;
            
            BNode* pai = criaNo(arvore);            
            pai->filhos[0] = no;
            adicionaChaveNo(pai, novo, promovido);
            
            no->pai = pai;
            novo->pai = pai;
            arvore->raiz = pai;
        } else
            adicionaChaveRecursivo(arvore, no->pai, novo, promovido);
    }
}

void adicionaChave(ArvoreB* arvore, int chave) {
    BNode* no = localizaNo(arvore, chave);

    adicionaChaveRecursivo(arvore, no, NULL, chave);
}

void freeB_rec(ArvoreB* arvore,BNode* no){
    free(no->chaves);
    for(int i=0;i < no->total;i++){
        freeB_rec(arvore,no->filhos[i]);
        free(no->filhos[i]);
    }
    free(no);
}
void freeB(ArvoreB* arvore){
    freeB_rec(arvore,arvore->raiz);
}