/*typedef struct LinkedNode LinkedNode;
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

void liberar_lista(LinkedNode *inicio){
    if(inicio == NULL) return;
    liberar_lista(inicio->next);
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

void liberar_nos(LinkedNode *head, LinkedNode *tail) {
    if (head == tail) {
        return;
    }
    liberar_nos(head->next, tail);
    free(head);
}

int compare(char a, char b) {
    if ((a == 'A' && b == 'T') || (a == 'T' && b == 'A')
        || (a == 'C' && b == 'G') || (a == 'G' && b == 'C'))
        return 1;
    else
        return 0;
}

LinkedNode *match(LinkedNode *head, LinkedNode *bond) {
    for (; head != NULL; head = head->next, bond = bond->next) {
        if (! compare(head->data, bond->data)) {
            return NULL;
        } else if (bond->next == NULL) {
            return head;
        }
    }
    return NULL;
}

LinkedNode *editar_dna(LinkedNode *dna_original, LinkedNode *seq_edicao){
    LinkedNode *matched, *matchednext, *tmp;

    // remove leading matched subsequence(s) as a preproces
    while ((matched = match(dna_original, seq_edicao))) {
        matchednext = matched->next;
        liberar_nos(dna_original->next, matched->next); // note we cannot free the 1st node
        dna_original->data = matchednext->data;
        dna_original->next = matchednext->next;
    }

    for (tmp = dna_original; tmp != NULL; tmp = tmp->next) {
        if ((matched = match(tmp->next, seq_edicao))) {
            matchednext = matched->next;
            liberar_nos(tmp->next, matched->next);
            tmp->next = matchednext;
        }
    }

    return dna_original;
}

int main(){

    //Creating empty nodes
    LinkedNode *dna_original = NULL;
    LinkedNode *sequencia = NULL;

    //Populating test data into the original sequence
//    dna_original = inserir_final_r(dna_original, 'A');        // dropped just for the test
    dna_original = inserir_final_r(dna_original, 'C');
    dna_original = inserir_final_r(dna_original, 'G');
    dna_original = inserir_final_r(dna_original, 'T');
    dna_original = inserir_final_r(dna_original, 'C');
    dna_original = inserir_final_r(dna_original, 'G');
    dna_original = inserir_final_r(dna_original, 'T');
    dna_original = inserir_final_r(dna_original, 'A');
    dna_original = inserir_final_r(dna_original, 'C');
    dna_original = inserir_final_r(dna_original, 'G');
    dna_original = inserir_final_r(dna_original, 'T');
    dna_original = inserir_final_r(dna_original, 'A');

    //Populating test data into the second sequence
    sequencia = inserir_final_r(sequencia, 'G');
    sequencia = inserir_final_r(sequencia, 'C');
    sequencia = inserir_final_r(sequencia, 'A');

    //Printing the original sequence before change
    imprimir1(dna_original);

    //Changing the sequence
    editar_dna(dna_original, sequencia);

    //Printing the original sequence after change
    imprimir1(dna_original);

    //Freeing allocated memory
    liberar_lista(dna_original);
    liberar_lista(sequencia);

    return 0;
}*/

#include <stdlib.h>
#include <stdio.h>

typedef struct LinkedNode LinkedNode;
struct LinkedNode {
   char data;
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

void duplicar_pares1(LinkedNode *inicio){
    if (inicio == NULL){
        return;
    }
        LinkedNode *aux = inicio -> next;
        if ((inicio->data)% 2 == 0 ){
            LinkedNode *novo = malloc(sizeof(LinkedNode));
            novo -> data = inicio -> data;
            novo -> next = aux;
            duplicar_pares1(novo -> next);
            }
        duplicar_pares1(inicio -> next);
}

int main(){

    LinkedNode s3={88,NULL};

    LinkedNode s2={44,&s3};

    LinkedNode s1={11,&s2};

    imprimir1(&s1);

    duplicar_pares1(&s1);

    imprimir1(&s1);

    //DLinkedNode *inicio = NULL;

    //inicio = inserir_final(inicio, 4);
    //inicio = inserir_final(inicio, 1);
    //inicio = inserir_final(inicio, 1);

    //duplicar_pares2(inicio);

    //free(inicio);

    return 0;
}


