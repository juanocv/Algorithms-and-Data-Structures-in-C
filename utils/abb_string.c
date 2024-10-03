#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NoArvore NoArvore;
struct NoArvore {
    char *chave;
    NoArvore *esq, *dir;
};

NoArvore *buscar(NoArvore *raiz, char *chave) {
    if (raiz == NULL) return NULL;
    if (strcmp(chave, raiz->chave) == 0) return raiz;

    else if (strcmp(chave, raiz->chave) < 0)
        return buscar(raiz->esq, chave);
    else
        return buscar(raiz->dir, chave);
}

void arv_emordem (NoArvore* a){
    if (a != NULL) {
        arv_emordem(a->esq);
        puts(a->chave);
        arv_emordem(a->dir);
    }
}

char *minValueNode(NoArvore* no) {
    while (no->esq != NULL) no = no->esq;
    return no->chave;
}

NoArvore *inserir(NoArvore *raiz, char *chave_nova) {
    if (raiz == NULL) {
        NoArvore *novo_no = malloc(sizeof(NoArvore));
        novo_no->chave = malloc(sizeof(char)*100);
        strcpy(novo_no->chave, chave_nova);
        novo_no->esq = NULL;
        novo_no->dir = NULL;
        return novo_no;
    }
    if (strcmp(chave_nova, raiz->chave) < 0)
        raiz->esq = inserir(raiz->esq, chave_nova);
    else if (strcmp(chave_nova, raiz->chave) > 0)
        raiz->dir = inserir(raiz->dir, chave_nova);
    return raiz;
}

NoArvore *remover(NoArvore *raiz, char *chave) {
     if (raiz == NULL) return NULL;
     else if (strcmp(raiz->chave, chave) > 0) raiz->esq = remover(raiz->esq, chave);
     else if (strcmp(raiz->chave, chave) < 0) raiz->dir = remover(raiz->dir, chave);
     else {
        // sem filhos
        if (raiz->esq == NULL && raiz->dir == NULL) {
            free(raiz->chave);
            free(raiz);
            raiz = NULL;
        }
        // filho à direita
        else if (raiz->esq == NULL) {
            NoArvore *aux = raiz;
            raiz = raiz->dir;
            free(aux->chave);
            free(aux);
        }
        // filho à esquerda
        else if (raiz->dir == NULL) {
            NoArvore *aux = raiz;
            raiz = raiz->esq;
            free(aux->chave);
            free(aux);
        }
        // dois filhos (esq. e dir.)
        else {
            char* sucessor = minValueNode(raiz->dir);
            strcpy(raiz->chave,sucessor);
            raiz->dir = remover(raiz->dir, sucessor);
        }
     }
     return raiz;
}

void liberar_arvore(NoArvore *raiz) {
    if (raiz == NULL) return;
    liberar_arvore(raiz->esq);
    liberar_arvore(raiz->dir);
    free(raiz->chave);
    free(raiz);
}

int main(){

    //Creating empty node
    NoArvore *arv1 = NULL;

    //Populating test data in
    arv1 = inserir(arv1, "Adam");
    arv1 = inserir(arv1, "Ben");
    arv1 = inserir(arv1, "Suzy");
    arv1 = inserir(arv1, "Jim");
    arv1 = inserir(arv1, "Abel");

    arv_emordem(arv1);

    //busca = buscar(arv1, "Ben");
    //if(busca != NULL) puts(busca->chave);
    //else printf("No nao existe na arvore");
    printf("\n");
    remover(arv1, "Adam");

    arv_emordem(arv1);

    //Freeing allocated memory
    liberar_arvore(arv1);

    return 0;
}


