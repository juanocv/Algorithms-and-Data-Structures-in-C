#include <stdio.h>
#include <stdlib.h>

int main(){
    int m = 0, n = 0, i = -1, j = 1, k = 0;
    char oitavas[8], quartas[4], semi[2], fim;

    for (; j <= 15; j++){
        scanf("%d %d", &m, &n);
        i++;
        switch (j){
            case 1:
                if (m>n) oitavas[i]='A';
                else oitavas[i]='B';
                break;
            case 2:
                if (m>n) oitavas[i]='C';
                else oitavas[i]='D';
                break;
            case 3:
                if (m>n) oitavas[i]='E';
                else oitavas[i]='F';
                break;
            case 4:
                if (m>n) oitavas[i]='G';
                else oitavas[i]='H';
                break;
            case 5:
                if (m>n) oitavas[i]='I';
                else oitavas[i]='J';
                break;
            case 6:
                if (m>n) oitavas[i]='K';
                else oitavas[i]='L';
                break;
            case 7:
                if (m>n) oitavas[i]='M';
                else oitavas[i]='N';
                break;
            case 8:
                if (m>n) oitavas[i]='O';
                else oitavas[i]='P';
                i=-1; break;
            case 9:
                if (m>n) quartas[k]=oitavas[i];
                else quartas[k]=oitavas[i+1];
                i++; k++; break;
            case 10:
                if (m>n) quartas[k]=oitavas[i];
                else quartas[k]=oitavas[i+1];
                i++; k++; break;
            case 11:
                if (m>n) quartas[k]=oitavas[i];
                else quartas[k]=oitavas[i+1];
                i++; k++; break;
            case 12:
                if (m>n) quartas[k]=oitavas[i];
                else quartas[k]=oitavas[i+1];
                i=-1; k=0; break;
            case 13:
                if (m>n) semi[k]=quartas[i];
                else semi[k]=quartas[i+1];
                i++; k++; break;
            case 14:
                if (m>n) semi[k]=quartas[i];
                else semi[k]=quartas[i+1];
                i=-1; break;
            case 15:
                if (m>n) fim=semi[i];
                else fim=semi[i+1];
                break;
        }
    }

    for (i = 0; i < 8; i++){
        printf("%c ", oitavas[i]);
    }

    printf("\n");
    for (i = 0; i < 4; i++){
        printf("%c ", quartas[i]);
    }

    printf("\n");
    for (i = 0; i < 2; i++){
        printf("%c ", semi[i]);
    }

    printf("\n%c", fim);

    return 0;
}


