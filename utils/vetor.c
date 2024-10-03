/*Implemente a função valor_frequente, que recebe um vetor v de tamanho n e deve retornar qual o elemento mais frequente no vetor.*/

#include <stdio.h>
#include <stdlib.h>

int *expandir_vetor(const int *vetor, int n_compactado, int *n_expandido) {
    int i=0,j=0;
    *n_expandido=0;

    for(;i<n_compactado;i++){
        if(i%2!=0){
            *n_expandido+=vetor[i];
        }
    }

    int *novo_vetor=malloc(sizeof(int)*(*n_expandido)), count=0;
    for(i=0;i<n_compactado;i++){
        if(i%2!=0){
            for(;j<vetor[i]+count;j++){
                novo_vetor[j]=vetor[i-1];
            }
            count+=vetor[i];
        }
    }
    return novo_vetor;
}

int main(){
    int tam=0, i=0, j=0, tam_expand=0;

    scanf("%d", &tam);
    printf("\n");

    int e_vetor[tam];
    for(;i<tam;i++){
        scanf("%d", &e_vetor[i]);
        printf("\n");
    }

    int *vetor = expandir_vetor(e_vetor,tam,&tam_expand);

    for(;j<tam_expand;j++){
        printf("%d ", vetor[j]);
    }

    free(vetor);
    return 0;
}
