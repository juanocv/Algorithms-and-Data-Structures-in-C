#include <stdio.h>
#include <stdlib.h>

int intercala(int *v, int esq_inicio, int esq_fim, int dir_fim){
    int dir_inicio = esq_fim + 1;
    int esq = esq_inicio, dir = dir_inicio;

    int tam = dir_fim - esq_inicio + 1, comp = 0;
    int *v_aux = malloc(sizeof(int)*tam);

    for (int i = 0; i < tam; i++){
        if (esq > esq_fim) {
            v_aux[i] = v[dir++];
        }
        else if (dir > dir_fim) {
            v_aux[i] = v[esq++];
        }
        else if (v[esq] <= v[dir]) {
            v_aux[i] = v[esq++];
            comp++;
        }
        else {
            v_aux[i] = v[dir++];
            comp++;
        }
    }

    for (int i = 0; i < tam; i++){
        v[esq_inicio + i] = v_aux[i];
    }

    free(v_aux);
    return comp;
}

void merge_sort(int *v, int esq, int dir, int *comp){
    if (esq < dir) {
        int mid = (esq + dir)/2;
        merge_sort(v, esq, mid, comp);
        merge_sort(v, mid + 1, dir, comp);
        *comp += intercala(v, esq, mid, dir);
    }
}

int main() {
    int n_lista, comp = 0;

    scanf("%d", &n_lista);

    int *n_num = malloc(sizeof(int)*n_lista);

    for (int i = 0; i < n_lista; i++) scanf("%d", &n_num[i]);

    merge_sort(n_num, 0, n_lista - 1, &comp);

    if (n_lista == 0) printf("\nComparacoes: %d", n_lista);
    for (int i = 0; i < n_lista; i++) {
        if(i == n_lista - 1) printf("%d\nComparacoes: %d\n", n_num[i], comp);
        else printf("%d ", n_num[i]);
    }

    free(n_num);

    return 0;
}
