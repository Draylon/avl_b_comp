#ifndef AVL_HPP
#define AVL_HPP

extern int contadorAvl;

typedef struct noavl {
    struct noavl* pai;
    struct noavl* esquerda;
    struct noavl* direita;
    int valor;
} AvlNode;

typedef struct arvore {
    struct noavl* raiz;
} ArvoreAvl;

ArvoreAvl* criar();
int vazia(ArvoreAvl *arvore);
AvlNode* adicionarNo(AvlNode* no,int valor);
AvlNode* adicionar(ArvoreAvl* arvore,int valor);
void remover(ArvoreAvl* arvore,AvlNode* no);
AvlNode* localizar(AvlNode* no, int valor);
void percorrerProfundidadeInOrder(AvlNode* no, void(*callback) (int));
void percorrerProfundidadePreOrder(AvlNode* no, void(*callback) (int));
void percorrerProfundidadePosOrder(AvlNode* no, void(*callback) (int));
void visitar(int valor);
void balanceamento(ArvoreAvl*, AvlNode*);
int altura(AvlNode*);
int fb(AvlNode*);
AvlNode* rsd(ArvoreAvl*, AvlNode*);
AvlNode* rse(ArvoreAvl*, AvlNode*);
AvlNode* rdd(ArvoreAvl*, AvlNode*);
AvlNode* rde(ArvoreAvl*, AvlNode*);

#endif