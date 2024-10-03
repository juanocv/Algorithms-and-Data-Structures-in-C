/*Implemente a função imprimir_qtd_palavras, que recebe um texto e deve imprimir a quantidade de palavras em cada frase do texto. Considere que todas as frases terminam com um ponto final.

Protótipo da função:
void imprimir_qtd_palavras(char texto[]); */

#include <stdio.h>

void imprimir_qtd_palavras(char texto[]) {
    int i=0,qtd_palavras=1;
    do{
            if(texto[i]=='.'){
                printf("%d\n", qtd_palavras);
                qtd_palavras=0;
            }
            else if(texto[i]==' ' && texto[i+1]!=' ' && texto[i+1]!='.'){
                qtd_palavras++;
            }
            i++;
    }while(texto[i]!='\0');
}

int main(){
    char text[178];
    fgets(text, 178, stdin);
    imprimir_qtd_palavras(text);
    return 0;
}


/*
#include <stdio.h>

int main() {
    printf("Digite uma frase: ");

    char frase[29];
    fgets(frase, 29, stdin);
    puts(frase);
    return 0;
}
*/
