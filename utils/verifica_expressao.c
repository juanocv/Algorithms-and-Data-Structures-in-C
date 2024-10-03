#include <stdio.h>
#include <stdlib.h>

/*void imprimir(char vet[]){
    for(int i = 0; vet[i] != '\n'; i++){
        printf("%c", vet[i]);
    }
}*/

void inserir(char vet[], int size){
    for (int i = 0; i < size; i++){
        if (vet[i-1] == '\n') break;
        scanf("%c", &vet[i]);
    }
}

void verifica_expressao(char vet[], int size){
    int c_parent = 0, c_conc = 0, c_key = 0;
    int v_parent = 0, v_conc = 0, v_key = 0;

    for(int i = 0; vet[i] != '\0'; i++){
        switch(vet[i]){
            case '(':
                c_parent++;
                break;
            case ')':
                v_parent++;
                break;
            case '[':
                c_conc++;
                break;
            case ']':
                v_conc++;
                break;
            case '{':
                c_key++;
                break;
            case '}':
                v_key++;
                break;
        }
    }

    if (c_parent == v_parent && c_conc == v_conc && c_key == v_key) printf("SIM");
    else printf("NAO");
}


int main(){
    int tam = 100;
    char exp[tam];

    inserir(exp,tam);
    verifica_expressao(exp,tam);

    return 0;
}


