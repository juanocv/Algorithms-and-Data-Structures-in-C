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

void arv_emordem (NoArvore* a)
{
 if (a != NULL) {
    arv_emordem(a->esq);
    printf("%d ",a->chave);
    arv_emordem(a->dir);
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

void find_suc_ant(NoArvore *raiz, NoArvore *esq, NoArvore *dir, int opcao, int chave, int *retorno){
    if(raiz != NULL){

        if (*retorno == 0 || opcao == 2){
            find_suc_ant(raiz->esq, esq, raiz, opcao, chave, retorno);
        }
        if (*retorno == 0 || opcao == 2){
            find_suc_ant(raiz->dir, raiz, dir, opcao, chave, retorno);
        }
        else return;

        switch(opcao){
            //Opcao = 1: Predecessor
            case 1:
                if(raiz->dir == NULL && dir != NULL && dir->chave == chave){
                    *retorno = raiz->chave;
                }
                else if(raiz->esq == NULL && esq != NULL && raiz->chave == chave){
                    *retorno = esq->chave;
                }
                else if(raiz->esq == NULL && raiz->chave == chave && esq == NULL){
                    *retorno = -1;
                }

            //Opcao = 1: Sucessor
            case 2:
                if(raiz->esq == NULL && esq != NULL && esq->chave == chave){
                    *retorno = raiz->chave;
                }
                else if(raiz->dir == NULL && dir != NULL && raiz->chave == chave){
                    *retorno = dir->chave;
                }
                else if(raiz->dir == NULL && dir == NULL && raiz->chave == chave){
                    *retorno = -1;
                }
            break;
        }
    }
}

int sucessor(NoArvore *raiz, int chave) {
    int suc = 0;
    find_suc_ant(raiz, NULL, NULL, 2, chave, &suc);
    return suc;
}

int predecessor(NoArvore *raiz, int chave) {
    int ant = 0;
    find_suc_ant(raiz, NULL, NULL, 1, chave, &ant);
    return ant;
}

int main(){

    //Creating empty node
    NoArvore *arv1 = NULL;

    //Populating test data in
    arv1 = inserir(arv1, 120);
    arv1 = inserir(arv1, 110);
    arv1 = inserir(arv1, 150);
    arv1 = inserir(arv1, 250);
    arv1 = inserir(arv1, 200);
    arv1 = inserir(arv1, 1);
    arv1 = inserir(arv1, 2);
    arv1 = inserir(arv1, 90);
    arv1 = inserir(arv1, 10);
    arv1 = inserir(arv1, 100);
    arv1 = inserir(arv1, 20);
    arv1 = inserir(arv1, 160);

    arv_emordem(arv1);

    printf("\n%d", predecessor(arv1, 1));

    printf("\n%d", predecessor(arv1, 250));

    printf("\n%d", predecessor(arv1, 90));

    printf("\n%d", predecessor(arv1, 120));

    printf("\n%d", predecessor(arv1, 160));

    printf("\n%d", predecessor(arv1, 100));

    printf("\n%d", predecessor(arv1, 110));


    //Freeing allocated memory
    liberar_arvore(arv1);

    return 0;
}


