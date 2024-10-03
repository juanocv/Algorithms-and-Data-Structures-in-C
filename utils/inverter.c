#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedNode LinkedNode;
struct LinkedNode {
   int data;
   LinkedNode *next;
};

LinkedNode* inverter_lista(LinkedNode *inicio){
    LinkedNode *anterior = NULL;
    LinkedNode *atual = inicio;
    LinkedNode *next;

    if (atual == NULL) return NULL;

    while(atual!=NULL){
        next=atual->next;
        atual->next=anterior;
        anterior=atual;
        atual=next;
    }
    return anterior;
}

int main(){

    LinkedNode l4={4,NULL};

    LinkedNode l3={3,&l4};

    LinkedNode l2={2,&l3};

    LinkedNode l1={1,&l2};

    LinkedNode l4 = inverter_lista(&l1);

    return 0;
}
