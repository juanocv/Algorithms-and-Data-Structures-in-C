#include <stdio.h>
#include <stdlib.h>

typedef struct NoArvore NoArvore;
struct NoArvore {
    int chave;
    NoArvore *esq, *dir;
};

void liberar_arvore(NoArvore *raiz) {
    if (raiz == NULL) return;
    liberar_arvore(raiz->esq);
    liberar_arvore(raiz->dir);
    free(raiz);
}

int arv_vazia (NoArvore* a)
{
 return a==NULL;
}

void arv_preordem (NoArvore* a)
{
 if (!arv_vazia(a)){
    printf("%d ",a->chave); /* mostra raiz */
    arv_preordem(a->esq); /* mostra sae */
    arv_preordem(a->dir); /* mostra sad */
 }
}

void arv_posordem (NoArvore* a)
{
 if (!arv_vazia(a)){
    arv_posordem(a->esq); /* mostra sae */
    arv_posordem(a->dir); /* mostra sad */
    printf("%d\n",a->chave); /* mostra raiz */
 }
}

NoArvore *inserir(NoArvore *raiz, int chave_nova) {
    if (raiz == NULL) {
    NoArvore *novo_no = malloc(sizeof(NoArvore));
    novo_no->chave = chave_nova;
    novo_no->esq = NULL;
    novo_no->dir = NULL;
    return novo_no;
    }
    if (chave_nova < raiz->chave)
        raiz->esq = inserir(raiz->esq, chave_nova);
    else if (chave_nova > raiz->chave)
        raiz->dir = inserir(raiz->dir, chave_nova);
    return raiz;
}


int menor(NoArvore *raiz){
    if (raiz==NULL) return -1;
    while (raiz->esq!=NULL) raiz = raiz->esq;
    return raiz->chave;
}

int maior(NoArvore *raiz){
    if (raiz==NULL) return -1;
    while (raiz->dir!=NULL) raiz = raiz->dir;
    return raiz->chave;
}

/*NoArvore *buscaNo(NoArvore *raiz, int chave_busca) {
    if (raiz == NULL) return NULL;
    if (chave_busca == raiz->chave) return raiz;

    else if (chave_busca < raiz->chave)
        return buscaNo(raiz->esq, chave_busca);
    else
        return buscaNo(raiz->dir, chave_busca);
}*/

int main(){


    NoArvore *arv = NULL;

    //Populating test data in
    arv = inserir(arv, 170);
    arv = inserir(arv, 160);
    arv = inserir(arv, 150);
    arv = inserir(arv, 140);
    arv = inserir(arv, 130);
    arv = inserir(arv, 120);
    arv = inserir(arv, 110);

    arv_preordem(arv);

    printf("\n%d\n", menor(arv));

    arv_preordem(arv);

    printf("\n%d", maior(arv));

    //Freeing allocated memory
    liberar_arvore(arv);

    return 0;
}


