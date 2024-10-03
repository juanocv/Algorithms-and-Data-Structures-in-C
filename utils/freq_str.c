/*Implemente a função valor_frequente, que recebe um vetor v de tamanho n e deve retornar qual o elemento mais frequente no vetor.*/

#include <stdio.h>
#include <stdlib.h>

void frequencia_string(const char *str, const char *texto, int *qtd) {
    int i=0, j=0;
    *qtd=0;

    for(;texto[i]!='\0';){
        if(str[j]=='\0'){
            *qtd=*qtd+1;
            i--;
        }
        for(j=0;str[j]!='\0';j++){
            if(texto[i]==str[j] || texto[i]+32==str[j] || texto[i]-32==str[j]){
                i++;
            }
            else{
                i++;
                break;
            }
        }
    }
}

int main(){
    int qtde=0;
    char palavra[4], texto[28];

    fgets(palavra, 4, stdin);
    fflush(stdin);
    fgets(texto, 28, stdin);

    frequencia_string(palavra, texto, &qtde);

    printf("%d", qtde);
    return 0;
}
