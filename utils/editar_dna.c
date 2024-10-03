#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedNode LinkedNode;
struct LinkedNode {
   char data;
   LinkedNode *next;
};

void imprimir1(LinkedNode *inicio){
    if(inicio == NULL){
    return;
    }

    printf("%c", inicio->data);
    if (inicio->next!=NULL) printf(" ");
    else printf("\n");
    imprimir1(inicio->next);
    return;
}

void liberar_lista1(LinkedNode *inicio){
    if(inicio == NULL) return;
    liberar_lista1(inicio->next);
    free(inicio);
}

LinkedNode *inserir_final_r(LinkedNode *inicio, char valor) {
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

int bases_dna(LinkedNode *atual, LinkedNode *seq_edicao){
    int i = 0, k = 0, seq_count = 0;
    LinkedNode *seq_new = seq_edicao;

    while(seq_new!=NULL){
        seq_new = seq_new->next;
        seq_count++;
    }

    seq_new = seq_edicao;
    for(; i<seq_count; i++){
        if ((atual->data == 'C' && seq_new->data == 'G') ||
            (atual->data == 'A' && seq_new->data == 'T') ||
            (atual->data == 'G' && seq_new->data == 'C') ||
            (atual->data == 'T' && seq_new->data == 'A')){
                k++;
                atual = atual->next;
                seq_new = seq_new->next;
        }
    }

    if(k==seq_count) return k;
    else return 0;
}

LinkedNode *editar_dna(LinkedNode *dna_original, LinkedNode *seq_edicao){
    LinkedNode *anterior = NULL, *atual = NULL;

    for(atual = dna_original; atual != NULL; atual = atual->next){
        int k = bases_dna(atual, seq_edicao);
        for(int i = 0; i<k; i++, atual = atual->next){
            LinkedNode *novo = atual;
            if (anterior==NULL){
                dna_original=atual->next;
            }
            else{
                anterior->next = atual->next;
            }
            free(novo);
        }
        anterior = atual;
    }
    return dna_original;
}

int main(){

    LinkedNode *dna_original = NULL;
    LinkedNode *sequencia = NULL;

    dna_original = inserir_final_r(dna_original, 'A');
    dna_original = inserir_final_r(dna_original, 'C');
    dna_original = inserir_final_r(dna_original, 'G');
    dna_original = inserir_final_r(dna_original, 'T');
    dna_original = inserir_final_r(dna_original, 'A');
    dna_original = inserir_final_r(dna_original, 'C');
    dna_original = inserir_final_r(dna_original, 'G');
    dna_original = inserir_final_r(dna_original, 'T');
    dna_original = inserir_final_r(dna_original, 'A');

    sequencia = inserir_final_r(sequencia, 'G');
    sequencia = inserir_final_r(sequencia, 'C');
    sequencia = inserir_final_r(sequencia, 'A');

    imprimir1(dna_original);

    editar_dna(dna_original, sequencia);

    imprimir1(dna_original);

    liberar_lista1(dna_original);
    liberar_lista1(sequencia);

    return 0;
}
