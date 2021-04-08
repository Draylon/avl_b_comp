#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct no {
    int total;
    int* chaves;
    struct no** filhos;
    struct no* pai; 
} No;

typedef struct arvoreB {
  No* raiz;
  int ordem;
} ArvoreB;

ArvoreB* criaArvore(int);
No* criaNo(ArvoreB*);
void percorreArvore(No*);
int pesquisaBinaria(No*, int);
int localizaChave(ArvoreB*, int);
No* localizaNo(ArvoreB*, int);
void adicionaChaveNo(No*, No*, int);
int transbordo(ArvoreB*,No*);
No* divideNo(ArvoreB*, No*);
void adicionaChaveRecursivo(ArvoreB*, No*, No*, int);
void adicionaChave(ArvoreB*, int);

int count_total_op=0;

ArvoreB* criaArvore(int ordem) {
    ArvoreB* a = malloc(sizeof(ArvoreB));
    a->ordem = ordem;
    a->raiz = criaNo(a);

    return a;
}

int contador = 0;

No* criaNo(ArvoreB* arvore) {
    int max = arvore->ordem * 2;
    No* no = malloc(sizeof(No));

    no->pai = NULL;
        
    no->chaves = malloc(sizeof(int) * (max + 1));
    no->filhos = malloc(sizeof(No) * (max + 2));
    no->total = 0;

    for (int i = 0; i < max + 2; i++)
        no->filhos[i] = NULL;

    return no;
}

void percorreArvore(No* no) {
    if (no != NULL) {
        for (int i = 0; i < no->total; i++){
            percorreArvore(no->filhos[i]); //visita o filho a esquerda
            
            printf("%d ",no->chaves[i]);
        }

        percorreArvore(no->filhos[no->total]); //visita ultimo filho (direita)
    }
}

int pesquisaBinaria(No* no, int chave) {
    int inicio = 0, fim = no->total - 1, meio;		
    
    while (inicio <= fim) {	
        contador++;
        
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
    No *no = arvore->raiz;
    
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

No* localizaNo(ArvoreB* arvore, int chave) {	
    No *no = arvore->raiz;
    
    while (no != NULL) {
        contador++;

        int i = pesquisaBinaria(no, chave);

        if (no->filhos[i] == NULL)
            return no; //encontrou nó
        else
            no = no->filhos[i];
    }

    return NULL; //não encontrou nenhum nó
}

void adicionaChaveNo(No* no, No* novo, int chave) {
    int i = pesquisaBinaria(no, chave);
    
    contador++;

    for (int j = no->total - 1; j >= i; j--) {
        no->chaves[j + 1] = no->chaves[j];
        no->filhos[j + 2] = no->filhos[j + 1];
    }
    
    no->chaves[i] = chave;
    no->filhos[i + 1] = novo;

    no->total++;
}

int transbordo(ArvoreB* arvore, No* no) {
    contador++;
    
    return no->total > arvore->ordem * 2;
}

No* divideNo(ArvoreB* arvore, No* no) {
    int meio = no->total / 2;
    No* novo = criaNo(arvore);
    novo->pai = no->pai;

    contador++;
    
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

void adicionaChaveRecursivo(ArvoreB* arvore, No* no, No* novo, int chave) {
    contador++;
    
    adicionaChaveNo(no, novo, chave);
    
    if (transbordo(arvore, no)) {
        int promovido = no->chaves[arvore->ordem]; 
        No* novo = divideNo(arvore, no);

        if (no->pai == NULL) {
            contador++;
            
            No* pai = criaNo(arvore);            
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
    contador = 0;
    No* no = localizaNo(arvore, chave);

    adicionaChaveRecursivo(arvore, no, NULL, chave);
}

int* random_array(const int size,const int order){
    int* rand_array = malloc(sizeof(int)*size);
    int ii=0;
    while(ii < size){
        int r_int = rand() % 100; // numeros de 0 a 200

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
    return rand_array;
}

int main() {

    srand(time(NULL));

    ArvoreB* tree = criaArvore(1);
    // Gera um array sem colisao
    int *array = random_array(100, 0);

    contador = 0;

    for (int i = 0; i < 100; i++) {
        adicionaChave(tree, array[i]);
         printf("%d,%d\n", i+1,contador);
    }

    // for (int i = 100; i >= 1; i--) {
    //     adicionaChave(tree, i);
    //     printf("%d\n", contador);
    // }

    percorreArvore(tree->raiz);
    free(array);
}
