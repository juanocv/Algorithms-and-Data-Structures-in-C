#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedNode LinkedNode;
struct LinkedNode {
   int data;
   LinkedNode *next;
};

typedef struct DLinkedNode DLinkedNode;
struct DLinkedNode {
   int data;
   DLinkedNode *next, *prev;
};

/*void imprimir2(DLinkedNode *inicio){
    DLinkedNode *atual, *anterior;
    for (atual = inicio; atual != NULL; atual = atual->next){
        anterior = atual;
        printf("%d ", atual->data);
    }
    printf("\n");
    for (atual = anterior; atual != NULL; atual = atual->prev)
        printf("%d ", atual->data);
    printf("\n");
}*/
/*
DLinkedNode *inserir_final(DLinkedNode *inicio, int valor) {
    DLinkedNode *novo = malloc(sizeof(DLinkedNode));
    if (novo == NULL) return inicio;
    novo->data = valor;
    novo->prev = NULL;
    novo->next = NULL;

    if (inicio == NULL) return novo;

    DLinkedNode *anterior = NULL;
    DLinkedNode *atual = inicio;
    while (atual != NULL) {
    anterior = atual;
    atual = atual->next;

    }
    novo->prev = anterior;
    anterior->next = novo;
    return inicio;
}

void imprimir1(LinkedNode *inicio){
    if(inicio == NULL){
    return;
    }

    printf("%d", inicio->data);
    if (inicio->next!=NULL) printf(" ");
    else printf("\n");
    imprimir1(inicio->next);
    return;
}
*/
void duplicar_pares1(LinkedNode *inicio){
    LinkedNode *atual = inicio;

    while(atual!=NULL){
        if((atual->data)%2 == 0){
            LinkedNode *novo = malloc(sizeof(LinkedNode));
            novo->data = atual->data;
            novo->next = atual->next;
            atual->next = novo;
            atual=atual->next->next;
        }
        else{
            atual=atual->next;
        }
    }
}

/*
void duplicar_pares2(DLinkedNode *inicio){
    DLinkedNode *atual = inicio;

    while(atual!=NULL){
        if((atual->data)%2 == 0){
            DLinkedNode *novo = malloc(sizeof(DLinkedNode));
            novo->data = atual->data;
            novo->next = atual->next;
            atual->next = novo;
            novo->prev = atual;
            atual=atual->next->next;
            if (novo->next != NULL) novo->next->prev = novo;
        }
        else{
            atual=atual->next;
        }
    }
}
*/
int main(){

    LinkedNode s3={88,NULL};

    LinkedNode s2={44,&s3};

    LinkedNode s1={11,&s2};

    duplicar_pares1(&s1);

    //DLinkedNode *inicio = NULL;

    //inicio = inserir_final(inicio, 4);
    //inicio = inserir_final(inicio, 1);
    //inicio = inserir_final(inicio, 1);

    //duplicar_pares2(inicio);

    //free(inicio);

    return 0;
}
