/*Leia uma sequ�ncia de n inteiros e mostre quantos s�o pot�ncias de 2.

Observa��o: n�o utilize math.h.*/


#include <stdio.h>

int main()
{
    int lenght, i, pot, unid_pots=0;
    scanf("%d", &lenght);

    int vet[lenght];
    for(i=0; i<lenght; i++){
        scanf("%d", &vet[i]);

        pot=1;
        while (vet[i]!=1) {
                if (vet[i]%2!=0) {
                        pot=0;
                        break;}
                vet[i]=vet[i]/2;
                if(vet[i]<1) {
                        pot=0;
                        break;
                }
        }
        if (pot==1) {
            unid_pots++;
        }
    }
    printf("%d", unid_pots);
    return 0;
}
