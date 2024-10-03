/*Escreva um programa que leia um vetor de números inteiros e então imprima a maior sequência (sequência mais longa)
de valores ordenados consecutivos (ordem crescente).

Por exemplo, para o vetor [10 20 30 1 2 3 4 11 22], o programa deve imprimir a sequência 1 2 3 4, que é a maior sequência
de valores ordenados consecutivos no vetor (essa sequência possui 4 elementos).

                            11 22 10 20 30 1 2 3 4*/


#include <stdio.h>

void maior_sequencia(int v[], int size){
    int j, k=0, count=0, aux=0, pos=0;
    float curr_patt=0, old_patt=0, future_patt=0;

    for(j=0;j<size;j++){
            count++;
            old_patt=curr_patt;
            curr_patt=(v[j+1]-v[j]);

            if (old_patt<0 && curr_patt>0){
                    count=1;
            }
            else if (old_patt<0){
                    count=0;
            }
            else if ((old_patt==0) || (curr_patt-old_patt)==0){
                    continue;
            }
            else {
                if(aux<count){
                    aux=count;
                    count=0;
                    pos=j;
                }
            }
    }
    for(k=pos-aux+1;k<=pos;k++){
        printf("%d ", v[k]);
    }
}

int main(){
    int i,tam;
    scanf("%d", &tam);

    int element[tam];
    for(i=0;i<tam;i++){
            scanf("%d", &element[i]);
    }

    maior_sequencia(element,tam);
    /*for(i=0;i<tam;i++){
            printf("%d\n", element[i]);
    }*/
}
