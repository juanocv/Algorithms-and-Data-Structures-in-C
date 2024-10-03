#include <stdio.h>

typedef struct Fracao Fracao;
struct Fracao {
    int numerador, denominador;
};

void simplificar(Fracao *fr){
    int i, j;
    float menor_numero;

    menor_numero = fr->numerador < fr->denominador ? fr->numerador : fr->denominador;

    for(j = menor_numero; j > 1; --j){
        if (fr->numerador % j == 0 && fr->denominador % j == 0){
            fr->denominador /= j;
            fr->numerador /= j;
            break;
        }
    }
}

Fracao somar(Fracao f1, Fracao f2) {
    int irred_num = (f1.numerador * f2.denominador + f1.denominador * f2.numerador);
    int irred_den = f1.denominador * f2.denominador;
    int mmc;

    if(f1.denominador == f2.denominador){
        f2.numerador = f1.numerador + f1.numerador;
    }
    else{
        for (int i = 1; i <= irred_num && i <= irred_den; ++i){
            if (irred_num % i == 0 && irred_den % i == 0){
            mmc = i;
            }
        }
        f2.numerador = irred_num/mmc;
        f2.denominador = irred_den/mmc;
    }
    simplificar(&f2);
    return f2;
}

Fracao multiplicar_vetor(Fracao f[], int n_fracoes) {
    Fracao res;
    res.numerador = 1, res.denominador = 1;

    for(int i = 0; i < n_fracoes; i++){
            res.numerador *= f[i].numerador;
            res.denominador *= f[i].denominador;
    }
    simplificar(&res);
    return res;
}


Fracao somar_vetor(Fracao f[], int n_fracoes) {
    int i = 0, j = 1, irred_num = 0, irred_den = 0, mmc = 0;

    for(i; i+1 < n_fracoes; i++){
        irred_num =(f[i].numerador * f[i+1].denominador + f[i].denominador * f[i+1].numerador);
        irred_den = f[i].denominador * f[i+1].denominador;

        if(f[i].denominador == f[i+1].denominador){
            f[i+1].numerador = f[i].numerador + f[i+1].numerador;
        }
        else{
            for (j = 1; j <= irred_num && j <= irred_den; ++j){
                if (irred_num % j == 0 && irred_den % j == 0){
                mmc = j;
                }
            }
            f[i+1].numerador = irred_num/mmc;
            f[i+1].denominador = irred_den/mmc;
        }
    }
    simplificar(&f[i]);
    return f[i];
}

Fracao multiplicar(Fracao f1, Fracao f2) {
    f1.numerador = f1.numerador*f2.numerador;
    f1.denominador = f1.denominador*f2.denominador;
    simplificar(&f1);

    return f1;
}
/*
int main(){

    int numerador, denominador, i, j;
    float menor_numero;

    printf("Numerador: ");
    scanf("%d",&numerador);

    printf("Denominador: ");
    scanf("%d",&denominador);

    menor_numero = numerador < denominador ? numerador : denominador;

    for(j = menor_numero; j > 1; --j){
        if (numerador % j == 0 && denominador % j == 0){
            denominador /= j;
            numerador /= j;
            break;
        }
    }

printf("Fracao reduzida : %d/%d\n", numerador, denominador);

}

int main(){
    Fracao fr1, fr2;

    printf("Numerador 1: ");
    scanf("%d",&fr1.numerador);

    printf("Denominador 1: ");
    scanf("%d",&fr1.denominador);

    printf("Numerador 2: ");
    scanf("%d",&fr2.numerador);

    printf("Denominador 2: ");
    scanf("%d",&fr2.denominador);

    Fracao fr3 = somar(fr[], fr2);

    printf("\nApos a adicao temos: %d/%d", fr3.numerador, fr3.denominador);
}*/

int main(){
    Fracao fr[4];

    fr[0].numerador=3;
    fr[0].denominador=2;
    fr[1].numerador=3;
    fr[1].denominador=6;
    fr[2].numerador=5;
    fr[2].denominador=25;
    fr[3].numerador=7;
    fr[3].denominador=5;

    Fracao f = somar_vetor(fr, 4);

    printf("Apos a adicao temos: %d/%d", f.numerador, f.denominador);
}
