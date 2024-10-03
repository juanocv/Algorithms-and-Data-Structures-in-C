#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedNode LinkedNode;
struct LinkedNode {
   int data;
   LinkedNode *next;
};

void imprimir(LinkedNode *inicio){
    if(inicio == NULL){
    return;
    }

    printf("%d", inicio->data);
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

LinkedNode *selection_sort(LinkedNode *inicio, int *trocas, int *comparacoes){
    *trocas = 0, *comparacoes = 0;
    if(inicio != NULL){
        for (LinkedNode *count = inicio; count->next != NULL; count = count->next) {
            LinkedNode *menor = count;
            for (LinkedNode *count2 = count->next; count2 != NULL; count2 = count2->next) {
                if (menor->data > count2->data) menor = count2;
                *comparacoes+=1;
            }
            if (menor->data != count->data){
                *trocas+=1;
                int aux = menor->data;
                menor->data = count->data;
                count->data = aux;
            }
        }
    }
    printf("t:%d c:%d\n", *trocas, *comparacoes);
    return inicio;
}


int main(){

    //Neste exercício, não é necessário alterar a estrutura da lista,
    //apenas a mudança das chaves é suficiente

    //Não é permitido alocar novos nós e nem utilizar vetor.

    LinkedNode *elementos = NULL;
    int t = 0, c = 0;

    elementos = inserir_final_r(elementos, 11);
    elementos = inserir_final_r(elementos, 22);
    elementos = inserir_final_r(elementos, 33);
    elementos = inserir_final_r(elementos, 44);
    elementos = inserir_final_r(elementos, 55);

    imprimir(elementos);

    selection_sort(elementos, &t, &c);

    imprimir(elementos);

    liberar_lista(elementos);

    return 0;
}
