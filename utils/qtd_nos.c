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

void numero_nos_aux(NoArvore *head, int opcao, int *qtd_nos){
    switch(opcao){
        case 1:
            if (head != NULL){
                *qtd_nos+=1;
                numero_nos_aux(head->esq, opcao, qtd_nos);
                numero_nos_aux(head->dir, opcao, qtd_nos);
            } break;
        case 2:
            if (head != NULL){
                if (head->esq == NULL && head->dir == NULL) *qtd_nos+=1;
                numero_nos_aux(head->esq, opcao, qtd_nos); /* mostra sae */
                numero_nos_aux(head->dir, opcao, qtd_nos); /* mostra sad */
            }
            break;
        case 3:
            if (head != NULL){
                if (head->esq == NULL && head->dir == NULL) *qtd_nos-=1;
                *qtd_nos+=1;
                numero_nos_aux(head->esq, opcao, qtd_nos);
                numero_nos_aux(head->dir, opcao, qtd_nos);
            }
            break;
    }
}

int numero_nos(NoArvore *raiz){ // recebe raiz da árvore e retorna quantos nós há na árvore
    int qtd = 0, caso = 1;
    numero_nos_aux(raiz, caso, &qtd);
    return qtd;
}

int numero_nos_folha(NoArvore *raiz){ // recebe raiz da árvore e retorna quantos nós folha há na árvore
    int qtd = 0, caso = 2;
    numero_nos_aux(raiz, caso, &qtd);
    return qtd;
}

int numero_nos_internos(NoArvore *raiz){ // recebe raiz da árvore e retorna quantos nós internos (não folha) há na árvore
    int qtd = 0, caso = 3;
    numero_nos_aux(raiz, caso, &qtd);
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


    NoArvore *arv = NULL;

    //Populating test data in
    arv = inserir(arv, 100);

    printf("%d", numero_nos(arv));
    printf("\n%d", numero_nos_folha(arv));
    printf("\n%d\n", numero_nos_internos(arv));

    arv = inserir(arv, 120);
    arv = inserir(arv, 140);
    arv = inserir(arv, 160);
    arv = inserir(arv, 130);
    arv = inserir(arv, 150);
    arv = inserir(arv, 170);

    arv_preordem(arv);

    printf("\n%d", numero_nos(arv));
    printf("\n%d", numero_nos_folha(arv));
    printf("\n%d", numero_nos_internos(arv));

    //Freeing allocated memory
    liberar_arvore(arv);

    return 0;
}


