#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedNode LinkedNode;
struct LinkedNode {
   int data;
   LinkedNode *next;
};

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

void liberar_lista(LinkedNode *inicio){
    if(inicio == NULL) return;
    liberar_lista(inicio->next);
    free(inicio);
}

LinkedNode *inserir_final_r(LinkedNode *inicio, int valor) {
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

int verificar_palindromo(struct LinkedNode** esq, struct LinkedNode* dir){
    if (dir == NULL) return 1;

    int res = verificar_palindromo(esq, dir->next) && ((*esq)->data == dir->data);
    (*esq) = (*esq)->next;

    return res;
}

int verificar_lista(LinkedNode *lista){
    return verificar_palindromo(&lista, lista);
}

int main(){

    //Creating empty nodes
    LinkedNode *lista = NULL;

    //Populating test data in
    lista = inserir_final_r(lista, 5);
    lista = inserir_final_r(lista, 0);
    lista = inserir_final_r(lista, 5);
    lista = inserir_final_r(lista, 0);
    lista = inserir_final_r(lista, 5);

    //Printing the original sequence
    imprimir1(lista);

    //Verifying if it is a palindrome
    if (verificar_lista(lista)) {
        printf("The linked list is a palindrome");
    }
    else {
        printf("The linked list is not a palindrome");
    }

    //Freeing allocated memory
    liberar_lista(lista);

    return 0;
}


