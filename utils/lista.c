#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedNode LinkedNode;
struct LinkedNode {
   int data;
   LinkedNode *next;
};

void contar(LinkedNode *inicio, int *qtd, int *soma){
    if(inicio == NULL){
        *qtd=0,*soma=0;
        return;
    }

    contar(inicio->next, qtd, soma);
    *qtd=*qtd+1;
    *soma=*soma+inicio->data;
    return;
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

void imprimir2_aux(LinkedNode *inicio, int count){
    if(inicio == NULL){
        return;
    }

    count++;
    imprimir2_aux(inicio->next, count);
    count--;
    if(count!=0) printf("%d ", inicio->data);
    else printf("%d", inicio->data);
    return;
}

void imprimir2(LinkedNode *inicio){
    imprimir2_aux(inicio, 0);
    printf("\n");
}

int main(){

    int qtd = 0, soma = 0;

    LinkedNode l3={10,NULL};

    LinkedNode l2={20,&l3};

    LinkedNode l1={30,&l2};

    contar(&l1,&qtd,&soma);
    imprimir1(&l1);
    imprimir2(&l1);

    return 0;
}
