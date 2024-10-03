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

    printf("%d", inicio->data);
    if (inicio->next!=NULL) printf(" ");
    else printf("\n");
    imprimir1(inicio->next);
    return;
}

LinkedNode* intercalar_listas(LinkedNode *inicio1, LinkedNode *inicio2){
    if (inicio1 == NULL)
        return(inicio2);
    else if (inicio2 == NULL)
        return(inicio1);

    if (inicio1->data <= inicio2->data) {
        inicio1->next = intercalar_listas(inicio1->next, inicio2);
        return inicio1;
    }
    else{
        inicio2->next = intercalar_listas(inicio1, inicio2->next);
        return inicio2;
    }
}

/*
LinkedNode* intercalar_listas(LinkedNode *inicio1, LinkedNode *inicio2){
    for (;inicio1!=NULL && inicio2!=NULL; inicio1 = inicio1->next, inicio2 = inicio2->next){
        printf("%d %d %d %d\n", inicio1->data, inicio2->data, inicio1->next->data, inicio2->next->data);
        inicio1=inicio2->next;
        inicio2->next=inicio1->next;
        inicio1->next=inicio2;
        printf("%d %d %d %d\n", inicio1->data, inicio2->data, inicio1->next->data, inicio2->next->data);
    }
}*/

int main(){

    LinkedNode l2={22,NULL};

    LinkedNode l1={11,&l2};


    LinkedNode s3={88,NULL};

    LinkedNode s2={44,&s3};

    LinkedNode s1={11,&s2};



    LinkedNode *n1 = intercalar_listas(&l1, &s1);

    imprimir1(n1);

    return 0;
}
