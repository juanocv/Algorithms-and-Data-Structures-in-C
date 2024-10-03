/* Implemente a função remover_numeros_matriz, que recebe uma matriz com n_linhas e n_colunas e também os índices de uma célula (l: linha, c: coluna).

A função deve incluir o valor zero na célula informada, assim como também em todas as células adjacentes que possuam o mesmo valor original da célula.

Ao trocar o valor de uma célula, as células adjacentes a esta também devem ser preenchidas com o valor zero. */

#include <stdio.h>

void remover_numeros_matriz(int l, int c, int n_linhas, int n_colunas, int m[n_linhas][n_colunas]) {
    int i, cell=m[l][c];

    for(i=-1;i<=1;i++){
        if(i==0){
            continue;
        }
        if(l+i>=0 && l+i<n_linhas){
            if(m[l+i][c]==cell){
                m[l][c]=0;
                remover_numeros_matriz(l+i, c, n_linhas, n_colunas, m);
            }
        }
        if(c+i>=0 && c+i<n_colunas){
            if(m[l][c+i]==cell){
                m[l][c]=0;
                remover_numeros_matriz(l, c+i, n_linhas, n_colunas, m);
            }
        }
    }

    m[l][c]=0;

}

int main(){
    int linha=0, coluna=0, num_l=0, num_c=0;
    scanf("%d %d %d %d", &num_l, &num_c, &linha, &coluna);
    printf("\n");

    int m[num_l][num_c], i=0, j=0;

    for(i=0;i<num_l;i++){
        for(j=0;j<num_c;j++){
            scanf("%d", &m[i][j]);
        }
        printf("\n");
    }

    for(i=0;i<num_l;i++){
        for(j=0;j<num_c;j++){
            printf(" %d ", m[i][j]);
        }
        printf("\n\n");
    }

    printf("==========================\n\n");

    remover_numeros_matriz(linha, coluna, num_l, num_c, m);

    for(i=0;i<num_l;i++){
        for(j=0;j<num_c;j++){
            printf(" %d ", m[i][j]);
        }
        printf("\n\n");
    }

    return 0;
}
