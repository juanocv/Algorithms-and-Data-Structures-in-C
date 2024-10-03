/*Implemente a função valor_frequente, que recebe um vetor v de tamanho n e deve retornar qual o elemento mais frequente no vetor.*/

#include "valor_freq.h"

int valor_frequente(int v[], int n) {
    int i,j,repete=0,count=0,valor_repet=0,valor_freq=0;
    for(i=0;i<n-1;i++){
        if(repete>count){
            count=repete;
            valor_freq=valor_repet;
        }
        repete=0;
        for(j=0;j<n-1;j++){
            if (v[i]==v[j]){
                repete++;
                valor_repet=v[i];
            }
        }
    }
  return valor_freq;
    
}