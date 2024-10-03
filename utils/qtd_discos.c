#include <stdio.h>
#include <stdlib.h>

void *quantidade_discos(char **discos, int n_discos, int **quantidade_por_fabricante) {
    int i=0;

    *quantidade_por_fabricante = malloc(sizeof(int*)*4);

    for(; i < 4 ; i++){
        ( * quantidade_por_fabricante)[i]=0;
    }

    for(i=0;i<n_discos;i++){
        switch(discos[i][7]){
            case 'A':
                (*quantidade_por_fabricante)[0]++;
                break;
            case 'B':
                (*quantidade_por_fabricante)[1]++;
                break;
            case 'C':
                (*quantidade_por_fabricante)[2]++;
                break;
            case 'D':
                (*quantidade_por_fabricante)[3]++;
                break;
        }
    }

    /*for(i=0;i<n_discos;i++){
        free(discos[i]);
    }

    for(i=0;i<4;i++){
        free(quantidade_por_fabricante_fab[i]);
    }

    free(quantidade_por_fabricante);
    free(discos);*/
}

int main(){
    int m_discos,i=0,n=0;

    scanf("%d", &m_discos);

    char **disks = malloc(sizeof(char*)*m_discos);
    int **qtd_fab = malloc(sizeof(int*)*4);

    for(;i<m_discos;i++){
        disks[i] = malloc(sizeof(char)*10);
    }

    for(i=0;i<4;i++){
        qtd_fab[i] = malloc(sizeof(int)*1);
    }

    for(;n<m_discos;n++){
        for(i=0;i<9;){
            scanf(" %c", &disks[n][i]);
            i++;
        }
        printf("\n");
    }

    /*for(n=0;n<m_discos;n++){
        for(i=0;i<9;i++){
            printf("%c", disks[n][i]);
        }
        printf(" ");
    }*/

    for(i=0;i<4;i++){
        for(n=0;n<1;n++){
            qtd_fab[i][n] = 0;
        }
    }

    quantidade_discos(disks, m_discos, qtd_fab);

    for(i=0;i<m_discos;i++){
        free(disks[i]);
    }

    for(i=0;i<4;i++){
        free(qtd_fab[i]);
    }

    free(qtd_fab);
    free(disks);
    return 0;
}
