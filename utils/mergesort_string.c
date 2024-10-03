#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedNode LinkedNode;
struct LinkedNode {
   char *data;
   LinkedNode *next;
};

void imprimir(LinkedNode *inicio){
    if(inicio == NULL){
    return;
    }

    printf("%s", inicio->data);
    if (inicio->next!=NULL) printf(" ");
    else printf("\n");
    imprimir(inicio->next);
    return;
}

void liberar_lista(LinkedNode *inicio){
    if(inicio == NULL) return;
    liberar_lista(inicio->next);
    free(inicio);
}

LinkedNode *inserir_final_r(LinkedNode *inicio, char *valor) {
    if (inicio == NULL) {
        LinkedNode *novo = malloc(sizeof(LinkedNode));
        if (novo == NULL) return inicio;
        novo->data = valor;
        novo->next = NULL;
        return novo;
    }
    inicio->next = inserir_final_r(inicio->next, valor);
    return inicio;
}

int my_cmpstr(LinkedNode *esq, LinkedNode *dir) {
    int i;

    for(i = 0; *(esq->data + i) != '\0' || *(dir->data + i) != '\0'; i++) {
        if (*(esq->data + i) < *(dir->data + i)) return 1;
        if (*(esq->data + i) > *(dir->data + i)) return 0;
    }
    if (*(esq->data + i) == '\0' && *(dir->data + i) != '\0') return 1;
    if (*(dir->data + i) == '\0' && *(esq->data + i) != '\0') return 0;
    else return 1;
}

LinkedNode *sort_merge(LinkedNode *esq, LinkedNode *dir, int *cmp){
    if (esq == NULL) return dir;
    else if (dir == NULL) return esq;

    LinkedNode *retorno = NULL;

    if (my_cmpstr(esq, dir) == 1) {
        (*cmp)++;
        retorno = esq;
        retorno->next = sort_merge(esq->next, dir, cmp);
    }
    else if (my_cmpstr(esq, dir) == 0){
        (*cmp)++;
        retorno = dir;
        retorno->next = sort_merge(esq, dir->next, cmp);
    }
    return retorno;
}

void merge_split(LinkedNode *v, LinkedNode **inicio, LinkedNode **fim) {

    if(v == NULL || v->next == NULL) {
        *inicio = v;
        *fim = NULL;
        return;
    }

    LinkedNode *meio = v;
    LinkedNode *ultimo = v->next;

    while (ultimo != NULL) {
        ultimo = ultimo->next;
        if (ultimo != NULL) {
            meio = meio->next;
            ultimo = ultimo->next;
        }
    }
    *inicio = v;
    *fim = meio->next;
    meio->next = NULL;
}

void merge_sort(LinkedNode **inicio, int *comparacoes) {
    LinkedNode *esq, *dir;

    if (*inicio == NULL || (*inicio)->next == NULL) return;

    merge_split(*inicio, &esq, &dir);

    merge_sort(&esq, comparacoes);
    merge_sort(&dir, comparacoes);

    *inicio = sort_merge(esq, dir, comparacoes);
}

LinkedNode *mergesort(LinkedNode *inicio, int *comparacoes) {
    *comparacoes = 0;
    merge_sort(&inicio, comparacoes);
    printf("%d", *comparacoes);
    imprimir(inicio);
    return inicio;
}

int main(){

    //Neste exercício, não é necessário alterar a estrutura da lista,
    //apenas a mudança das chaves é suficiente

    //Não é permitido alocar novos nós e nem utilizar vetor.

    LinkedNode *elementos = NULL;
    int t = 0, c = 0;

    elementos = inserir_final_r(elementos, "estruturada");
    elementos = inserir_final_r(elementos, "programacao");
    elementos = inserir_final_r(elementos, "fila");
    elementos = inserir_final_r(elementos, "lista");
    elementos = inserir_final_r(elementos, "ordenacao");
    elementos = inserir_final_r(elementos, "estrutura");
    elementos = inserir_final_r(elementos, "pilha");
    elementos = inserir_final_r(elementos, "processamento");
    elementos = inserir_final_r(elementos, "estruturas");
    elementos = inserir_final_r(elementos, "aplicativo");
    elementos = inserir_final_r(elementos, "arvore");
    elementos = inserir_final_r(elementos, "dados");
    elementos = inserir_final_r(elementos, "objetos");
    elementos = inserir_final_r(elementos, "algoritmos");
    //elementos = inserir_final_r(elementos, "F");

    imprimir(elementos);

    mergesort(elementos, &c);

    imprimir(elementos);

    liberar_lista(elementos);

    return 0;
}
