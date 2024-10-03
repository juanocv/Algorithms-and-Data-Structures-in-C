#include <stdio.h>
#include <stdlib.h>

void max_heapfy(int *v, int n, int i, int *cmp) {
    int esq = 2*i + 1, dir = 2*i + 2, maior = i;
    if (esq < n) {
        (*cmp)++;
        if (v[esq] > v[maior]) {
            maior = esq;
        }
    }
    if (dir < n) {
        (*cmp)++;
        if (v[dir] > v[maior]) {
            maior = dir;
        }
    }
    if (maior != i) {
        int aux = v[i];
        v[i] = v[maior];
        v[maior] = aux;
        max_heapfy(v, n, maior, cmp);
    }
}

void build_max_heap(int *v, int n, int *cmp) {
    for (int i = n/2 - 1; i >= 0; i--)
        max_heapfy(v, n, i, cmp);
}

int heapsort(int *v, int n) {
    int comp = 0;
    build_max_heap(v, n, &comp);
    for (int i = n-1; i > 0; i--) {
        int aux = v[i];
        v[i] = v[0];
        v[0] = aux;
        max_heapfy(v, i, 0, &comp);
    }
    return comp;
}

int main() {
    int tam = 8;
    //scanf("%d", &tam);

    //int *vetor = malloc(sizeof(int)*tam);
    int vetor[8] = {66, 33, 22, 55, 88, 11, 44, 77};
    //for (int i = 0; i < tam; i++) scanf("%d", &vetor[i]);

    for (int i = 0; i < tam; i++) printf("%d ", vetor[i]);
    printf("\n%d\n", heapsort(vetor, tam));

    for (int i = 0; i < tam; i++) printf("%d ", vetor[i]);

    //free(vetor);

    return 0;
}
