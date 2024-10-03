#include <stdio.h>
#include <stdlib.h>

typedef struct DLinkedNode DLinkedNode;
struct DLinkedNode {
   int data;
   DLinkedNode *prev, *next;
};

void imprimir(DLinkedNode *inicio){
    if(inicio == NULL){
    return;
    }

    printf("%d", inicio->data);
    if (inicio->next!=NULL) printf(" ");
    else printf("\n");
    imprimir(inicio->next);
    return;
}

void liberar_lista(DLinkedNode *inicio){
    if(inicio == NULL) return;
    liberar_lista(inicio->next);
    free(inicio);
}

DLinkedNode *inserir_final_r(DLinkedNode *inicio, DLinkedNode *anterior, int valor) {
    if (inicio == NULL) {
        DLinkedNode *novo = malloc(sizeof(DLinkedNode));
        if (novo == NULL) return inicio;
        novo->data = valor;
        novo->next = NULL;
        novo->prev = anterior;
        return novo;
    }
    inicio->next = inserir_final_r(inicio->next, inicio, valor);
    return inicio;
}

int comparar(DLinkedNode *anterior, int *cmp) {
    if (anterior != NULL && anterior->prev != NULL) {
        *cmp+=1;

        if (anterior->data < anterior->prev->data) {
            return 1;
        }
    }
}

DLinkedNode *insertion_sort(DLinkedNode *inicio, int *comparacoes){
    int cmp = 0;
    *comparacoes = 0;

    if(inicio != NULL){
        for (DLinkedNode *count = inicio; count != NULL; count = count->next) {
            DLinkedNode *anterior = count->next;
            for (; comparar(anterior, comparacoes) == 1; anterior = anterior->prev) {
                int aux = anterior->data;
                anterior->data = anterior->prev->data;
                anterior->prev->data = aux;
            }
        }
    }
    printf("c:%d\n", *comparacoes);
    return inicio;
}


int main(){

    //Neste exercício, não é necessário alterar a estrutura da lista,
    //apenas a mudança das chaves é suficiente

    //Não é permitido alocar novos nós e nem utilizar vetor.

    DLinkedNode *elementos = NULL;
    int t = 0, c = 0;

    elementos = inserir_final_r(elementos, elementos, 11);
    elementos = inserir_final_r(elementos, elementos, 22);
    elementos = inserir_final_r(elementos, elementos, 33);
    elementos = inserir_final_r(elementos, elementos, 44);
    elementos = inserir_final_r(elementos, elementos, 55);
    //elementos = inserir_final_r(elementos, elementos, 11);
    //elementos = inserir_final_r(elementos, elementos, 44);
    //elementos = inserir_final_r(elementos, elementos, 77);

    imprimir(elementos);

    insertion_sort(elementos, &c);

    imprimir(elementos);

    liberar_lista(elementos);

    return 0;
}
