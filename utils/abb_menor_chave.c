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

void busca_dois(NoArvore *raiz, int valor, int *menor){
    if (raiz == NULL) return NULL;
    if (valor == raiz->chave){
        *menor = valor;
    }

    else if (valor < raiz->chave)
        return busca_dois(raiz->esq, valor, menor);
    else
        return busca_dois(raiz->dir, valor, menor);
}

void percorre_um(NoArvore *raiz1, NoArvore *raiz2, int *menor, int *aux){
    if (raiz1 != NULL){
        busca_dois(raiz2, raiz1->chave, menor);
        if (*aux == 0) *aux = *menor;
        else if (*aux < *menor) *menor = *aux;
        else *aux = *menor;
        percorre_um(raiz1->esq, raiz2, menor, aux);
        percorre_um(raiz1->dir, raiz2, menor, aux);
    }
}

int menor_chave_comum(NoArvore *raiz1, NoArvore *raiz2) {
    int menor = 0, aux = 0;
    percorre_um(raiz1, raiz2, &menor, &aux);
    if (menor == 0) menor = -1;
    return menor;
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
    arv1 = inserir(arv1, 500);
    arv1 = inserir(arv1, 200);
    arv1 = inserir(arv1, 90);
    arv1 = inserir(arv1, 88);
    arv1 = inserir(arv1, 92);
    arv1 = inserir(arv1, 75);
    arv1 = inserir(arv1, 89);
    arv1 = inserir(arv1, 90);
    arv1 = inserir(arv1, 98);

    arv2 = inserir(arv2, 100);
    arv2 = inserir(arv2, 500);
    arv2 = inserir(arv2, 200);
    arv2 = inserir(arv2, 300);
    arv2 = inserir(arv2, 220);
    arv2 = inserir(arv2, 92);
    arv2 = inserir(arv2, 75);
    arv2 = inserir(arv2, 89);
    arv2 = inserir(arv2, 90);
    arv2 = inserir(arv2, 98);

    arv_preordem(arv1);
    printf("\n");
    arv_preordem(arv2);

    printf("\n%d", menor_chave_comum(arv1, arv2));

    //Freeing allocated memory
    liberar_arvore(arv1);
    liberar_arvore(arv2);

    return 0;
}


