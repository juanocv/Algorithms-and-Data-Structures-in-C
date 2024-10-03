/*Implemente a função valor_frequente, que recebe um vetor v de tamanho n e deve retornar qual o elemento mais frequente no vetor.*/

#include <stdio.h>
#include <stdlib.h>

void funcao(int a, int b, int *resultado) {
    int i=0,j=0,in=0;
    for(i=1;i<=a;i++){
        in=0;
        for(j=1;j<=b;j++){
            in = in +(i*j + 10);
            if(j==b){
                *resultado = *resultado + 5*i*in;
            }
        }
    }
    printf("%d\n", *resultado);
}

int main(){
    int e, f, result = 0;

    scanf("%d", &e);
    scanf("%d", &f);

    funcao(e, f, &result);

    free(result);
    return 0;
}
