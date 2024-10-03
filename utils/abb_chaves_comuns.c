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

void busca_dois(NoArvore *raiz, int valor, int *qtd){
    if (raiz == NULL) return NULL;
    if (valor == raiz->chave){
        *qtd+=1; return raiz;
    }

    else if (valor < raiz->chave)
        return busca_dois(raiz->esq, valor, qtd);
    else
        return busca_dois(raiz->dir, valor, qtd);
}

void percorre_um(NoArvore *raiz1, NoArvore *raiz2, int *qtd){
    if (raiz1 != NULL){
        busca_dois(raiz2, raiz1->chave, qtd);
        percorre_um(raiz1->esq, raiz2, qtd);
        percorre_um(raiz1->dir, raiz2, qtd);
    }
}

int qtd_chaves_comuns(NoArvore *raiz1, NoArvore *raiz2) {
    int qtd = 0;
    percorre_um(raiz1, raiz2, &qtd);
    return qtd;
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

    NoArvore *arv1 = NULL;
    NoArvore *arv2 = NULL;

    //Populating test data in
    arv1 = inserir(arv1, 100);
    arv1 = inserir(arv1, 120);
    arv1 = inserir(arv1, 140);
    arv1 = inserir(arv1, 160);
    arv1 = inserir(arv1, 130);
    arv1 = inserir(arv1, 150);
    arv1 = inserir(arv1, 170);

    arv2 = inserir(arv2, 110);
    arv2 = inserir(arv2, 180);
    arv2 = inserir(arv2, 140);
    arv2 = inserir(arv2, 160);
    arv2 = inserir(arv2, 100);
    arv2 = inserir(arv2, 190);
    arv2 = inserir(arv2, 200);

    arv_preordem(arv1);
    printf("\n");
    arv_preordem(arv2);

    printf("\n%d", qtd_chaves_comuns(arv1, arv2));

    //Freeing allocated memory
    liberar_arvore(arv1);
    liberar_arvore(arv2);

    return 0;
}


