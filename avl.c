#include <stdlib.h>
#include <stdio.h>
#include "avl.h"

contadorAvl=0;

ArvoreAvl* criar() {
    ArvoreAvl *arvore = malloc(sizeof(ArvoreAvl));
    arvore->raiz = NULL;
    return arvore;
}

int vazia(ArvoreAvl* arvore) {
    return arvore->raiz == NULL;
}

AvlNode* adicionarNo(AvlNode* no, int valor) {
    contadorAvl++;

    if (valor > no->valor) {
        if (no->direita == NULL) {
            //printf("Adicionando %d\n",valor);
            AvlNode* novo = malloc(sizeof(AvlNode));
            novo->valor = valor;
            novo->pai = no;
            novo->esquerda=NULL;
            novo->direita=NULL;

            no->direita = novo;
				
            return novo;
        } else {
            return adicionarNo(no->direita, valor);
        }
    } else {
        if (no->esquerda == NULL) {
            //printf("Adicionando %d\n",valor);
            AvlNode* novo = malloc(sizeof(AvlNode));
            
			novo->valor = valor;
            novo->pai = no;
			novo->direita=NULL;
            novo->esquerda=NULL;
            no->esquerda = novo;
            return novo;
        } else {
            return adicionarNo(no->esquerda, valor);
        }
    }
}

AvlNode* adicionar(ArvoreAvl* arvore, int valor) {
    if (arvore->raiz == NULL) {
        contadorAvl++;
        //printf("Adicionando %d\n",valor);
        AvlNode* novo = malloc(sizeof(AvlNode));
        novo->valor = valor;
        novo->direita=NULL;
        novo->esquerda=NULL;
        novo->pai=NULL;
        arvore->raiz = novo;
		
        return novo;
    } else {
        AvlNode* no = adicionarNo(arvore->raiz, valor);
        balanceamento(arvore, no);
        
        return no;
    }
}

void remover(ArvoreAvl* arvore, AvlNode* no) {
    if (no->esquerda != NULL) {
        remover(arvore, no->esquerda); 
    }
  
    if (no->direita != NULL) {
        remover(arvore, no->direita);
    }
  
    if (no->pai == NULL) {
        arvore->raiz = NULL;
    } else {
        if (no->pai->esquerda == no) {
            no->pai->esquerda = NULL;
        } else {
            no->pai->direita = NULL;
        }
    }

    free(no);
}

AvlNode* localizar(AvlNode* no, int valor) {
    if (no->valor == valor) {
        return no;
    } else {
        if (valor < no->valor) {
            if (no->esquerda != NULL) {
                return localizar(no->esquerda, valor);
            }
        } else {
            if (no->direita != NULL) {
                return localizar(no->direita, valor);
            }
        }
    }

    return NULL;
}

void percorrerProfundidadeInOrder(AvlNode* no, void (*callback)(int)) {
    if (no != NULL) {
        percorrerProfundidadeInOrder(no->esquerda,callback);
        callback(no->valor);
        percorrerProfundidadeInOrder(no->direita,callback);
    }
}

void percorrerProfundidadePreOrder(AvlNode* no, void (*callback)(int)) {
    if (no != NULL) {
        callback(no->valor);
        percorrerProfundidadePreOrder(no->esquerda,callback);
        percorrerProfundidadePreOrder(no->direita,callback);
    }
}

void percorrerProfundidadePosOrder(AvlNode* no, void (*callback)(int)) {
    if (no != NULL) {
        percorrerProfundidadePosOrder(no->esquerda,callback);
        percorrerProfundidadePosOrder(no->direita,callback);
        callback(no->valor);
    }
}

void visitar(int valor){
    //printf("%d ", valor);
    printf("");
}

void balanceamento(ArvoreAvl* arvore, AvlNode* no) {
    while (no != NULL) {
        int fator = fb(no);
        if (fator > 1) { //árvore mais pesada para esquerda
            //rotação para a direita
            if (fb(no->esquerda) > 0) {
                //printf("RSD(%d)\n",no->valor);
                rsd(arvore, no); //rotação simples a direita, pois o FB do filho tem sinal igual
            } else {
                //printf("RDD(%d)\n",no->valor);
                rdd(arvore, no); //rotação dupla a direita, pois o FB do filho tem sinal diferente
            }
        } else if (fator < -1) { //árvore mais pesada para a direita
            //rotação para a esquerda
            if (fb(no->direita) < 0) {
                //printf("RSE(%d)\n",no->valor);
                rse(arvore, no); //rotação simples a esquerda, pois o FB do filho tem sinal igual
            } else {
                //printf("RDE(%d)\n",no->valor);
                rde(arvore, no); //rotação dupla a esquerda, pois o FB do filho tem sinal diferente
            }
        }
        no = no->pai;
    }
}

int altura(AvlNode* no){
    contadorAvl++;
    int esquerda = 0,direita = 0;

    if (no->esquerda != NULL) {
        esquerda = altura(no->esquerda) + 1;
    }

    if (no->direita != NULL) {
        direita = altura(no->direita) + 1;
    }
  
    return esquerda > direita ? esquerda : direita; //max(esquerda,direita)
}

int fb(AvlNode* no) { // acho que não conta como operação
    int esquerda = 0,direita = 0;
  
    if (no->esquerda != NULL) {
        esquerda = altura(no->esquerda) + 1;
    }

    if (no->direita != NULL) {
        direita = altura(no->direita) + 1;
    }
    return esquerda - direita;
}

AvlNode* rse(ArvoreAvl* arvore, AvlNode* no) {
    contadorAvl++;
    AvlNode* pai = no->pai;
    AvlNode* direita = no->direita;
  
    no->direita = direita->esquerda;
    no->pai = direita;

    direita->esquerda = no;
    direita->pai = pai;

    if (pai == NULL) {
        arvore->raiz = direita;
    } else {
        if (pai->esquerda == no) {
            pai->esquerda = direita;
        } else {
            pai->direita = direita;
        }
    }

    return direita;
}

AvlNode* rsd(ArvoreAvl* arvore, AvlNode* no) {
    contadorAvl++;
    AvlNode* pai = no->pai;
    AvlNode* esquerda = no->esquerda;
  
    no->esquerda = esquerda->direita;
    no->pai = esquerda;
  
    esquerda->direita = no;
    esquerda->pai = pai;

    if (pai == NULL) {
        arvore->raiz = esquerda;
    } else {
        if (pai->esquerda == no) {
            pai->esquerda = esquerda;
        } else {
            pai->direita = esquerda;
        }
    }

    return esquerda;
}

AvlNode* rde(ArvoreAvl* arvore, AvlNode* no) {
    contadorAvl++;
    no->direita = rsd(arvore, no->direita);
    return rse(arvore, no);
}

AvlNode* rdd(ArvoreAvl* arvore, AvlNode* no) {
    contadorAvl++;
    no->esquerda = rse(arvore, no->esquerda);
    return rsd(arvore, no);
}

void freeAvl_rec(ArvoreAvl* arvore,AvlNode* node){
    if(node->esquerda != NULL){
        freeAvl_rec(arvore,node->esquerda);
        node->esquerda = NULL;
    }
    if(node->direita != NULL){
        freeAvl_rec(arvore,node->direita);
        node->direita = NULL;
    }
    free(node);
}

void freeAvl(ArvoreAvl* arvore){
    if(arvore->raiz != NULL)
        freeAvl_rec(arvore,arvore->raiz);
    free(arvore);
}

/*int main() {
    ArvoreAvl* a = criar();

    for (int i = 1; i <= 7; i++) {
        adicionar(a,i);  
    }

    printf("In-order: ");
    percorrerProfundidadeInOrder(a->raiz,visitar);
    printf("\n");
}*/