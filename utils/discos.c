#include <stdio.h>
#include <stdlib.h>

typedef struct Disco Disco;
struct Disco {
   int codigo;
   double preco;
};

void imprimir(Disco *inicio, int tam){
    int pos = 0;
    printf("\n");
    while (pos != tam) {
        printf("[%d][%.1lf] ", inicio[pos].codigo, inicio[pos].preco);
        pos++;
    }
}

int particiona(Disco *v, int esq, int dir, int tipo, int *comp) {
    Disco pivo = v[dir];

    int i, ultimo_menores = esq - 1;

    for (i = esq; i < dir; i++) {
        (*comp)++;
        if (v[i].codigo < pivo.codigo && tipo == 1 ||
            v[i].codigo > pivo.codigo && tipo == 2 ||
            v[i].preco < pivo.preco && tipo == 3) {

            ultimo_menores++;
            Disco tmp = v[i];
            v[i] = v[ultimo_menores];
            v[ultimo_menores] = tmp;
        }
        if (v[i].preco == pivo.preco && tipo == 3) {
            if (v[i].codigo < pivo.codigo) {
                ultimo_menores++;
                Disco tmp = v[i];
                v[i] = v[ultimo_menores];
                v[ultimo_menores] = tmp;
            }
        }
    }

    v[dir] = v[ultimo_menores+1];
    v[ultimo_menores+1] = pivo;
    return ultimo_menores + 1;
}

void quick_sort(Disco *v, int esq, int dir, int tipo, int *comp) {
    if (esq < dir) {
        printf("cmp_teste: %d", *comp);
        int indice_pivo = particiona(v, esq, dir, tipo, comp);
        //if (tipo == 3) indice_pivo = particiona_preco(v, esq, dir, comp);
        //else indice_pivo = particiona(v, esq, dir, tipo, comp);
        quick_sort(v, esq, indice_pivo - 1, tipo, comp);
        quick_sort(v, indice_pivo + 1, dir, tipo, comp);
    }
}

int quicksort(Disco *v, int n, int tipo) {
    int comparacoes = 0;
    quick_sort(v, 0, n - 1, tipo, &comparacoes);
    imprimir(v, n);
    return comparacoes;
}

int main(){
    int tam, tipo;
    scanf("%d", &tam);
    Disco *SeqDisco = malloc(sizeof(Disco)*tam);

    for(int i = 0; i < tam; i++) scanf("%d %lf", &SeqDisco[i].codigo, &SeqDisco[i].preco);
    scanf("%d", &tipo);

    imprimir(SeqDisco, tam);

    printf("\ntipo: %d\n", tipo);

    printf("\ncomp: %d\n", quicksort(SeqDisco, tam, tipo));

    free(SeqDisco);

    return 0;
}
