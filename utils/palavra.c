/*Implemente a função valor_frequente, que recebe um vetor v de tamanho n e deve retornar qual o elemento mais frequente no vetor.*/

#include <stdio.h>
#include <stdlib.h>

void substituir_palavra(char *texto, char *palavra1, char *palavra2) {
    int a=0, b=0, c=0, i=0, j=0, k=0, l=0, m=0, n=0;
    char aux[1], base[1];

    for(;palavra2[l]!='\0';){
        l++;
    }

    for(;texto[i]!='\0';){
        k=i-j;
        if((palavra1[j]=='\0' && texto[i]==' ') || (palavra1[j]=='\0' && texto[i]=='.')){
            if(l>j){
                for(;palavra1[m]!='\0';m++){
                    texto[k]=palavra2[m];
                    k++;
                }
                m=0;
                n=i;
                b=k;
                a=j;
                for(c=0;c<(l-j);c++){
                    for(k=b;texto[k]!='\0';k++){
                        if(k==b){
                            base[0]=texto[k+1];
                            texto[k+1]=texto[n];
                        }
                        else{
                            aux[0]=base[0];
                            base[0]=texto[k+1];
                            texto[k+1]=aux[0];
                        }
                    }
                texto[n]=palavra2[a];
                n++;
                b++;
                a++;
                }
            }
            else if(l<j){
                for(;palavra2[m]!='\0';m++){
                    texto[k]=palavra2[m];
                    k++;
                }
                m=0;
                b=k;
                for(c=0;c<(j-l);c++){
                    for(k=b;texto[k]!='\0';k++){
                        texto[k]=texto[k+1];
                    }
                }
            }
            else{
                for(c;c<l;c++){
                    texto[k]=palavra2[c];
                    k++;
                }
                c=0;
            }
            i--;
        }
        for(j=0;palavra1[j]!='\0';j++){
            if(texto[i]==palavra1[j]){
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
    char palavra1[5], palavra2[7], texto[54];

    gets(texto);
    gets(palavra1);
    gets(palavra2);

    substituir_palavra(texto, palavra1, palavra2);

    puts(texto);
    return 0;
}
