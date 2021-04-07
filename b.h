#ifndef B_HPP
#define B_HPP

extern int contadorB;

typedef struct nob {
    int total;
    int* chaves;
    struct nob** filhos;
    struct nob* pai; 
} BNode;

typedef struct arvoreB {
  BNode* raiz;
  int ordem;
} ArvoreB;



ArvoreB* criaArvore(int);
BNode* criaNo(ArvoreB*);
void percorreArvore(BNode*);
int pesquisaBinaria(BNode*, int);
int localizaChave(ArvoreB*, int);
BNode* localizaNo(ArvoreB*, int);
void adicionaChaveNo(BNode*, BNode*, int);
int transbordo(ArvoreB*,BNode*);
BNode* divideNo(ArvoreB*, BNode*);
void adicionaChaveRecursivo(ArvoreB*, BNode*, BNode*, int);
void adicionaChave(ArvoreB*, int);

void freeB();
void freeB_rec();

#endif