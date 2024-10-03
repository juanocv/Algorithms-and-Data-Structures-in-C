#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void imprimir_char(char *v, int n) {
    printf("[");
    for (int i = 0; i < n; i++) printf("%c", v[i]);
    printf("]\n");
}

void imprimir(int *v, int n) {
    printf("[");
    for (int i = 0; i < n + 1; i++) {
        if (i == (n + 1) - 1) printf("%d", v[i]);
        else printf("%d ", v[i]);
    }
    printf("]\n");
}

int char_to_index(char v, int *count) {
    if (v < 65 || v > 90) return -1;

    (*count)++;

    int i = 0;
    for(char j = 'A'; j < v; j++) i++;
    return i;
}

void countingsort(char *v, int n, int k) {
    int c[k + 1], i, count = 0, dummy = 0;

    for (i = 0; i < k + 1; i++) c[i] = 0;

    for (i = 0; i < n; i++) c[char_to_index(v[i], &count)]++;

    imprimir(c, k);

    for (i = 1; i < k + 1; i++) c[i] += c[i - 1];

    imprimir(c, k);

    char saida[n], atual;
    for (i = n - 1; i >= 0; i--) {
        atual = v[i];
        if (atual >= 65 && atual <= 90) {
            saida[c[char_to_index(atual, &dummy)] - 1] = atual;
            c[char_to_index(atual, &dummy)]--;
        }
    }

    for (i = 0; i < n; i++) v[i] = saida[i];

    imprimir_char(v, count);
}

int main() {
    int tam = 1000;
    char *vetor = malloc(sizeof(int)*tam);

    fgets(vetor, tam, stdin);
    //fgets(vetor, tam, stdin);
    //for (int i = 0; i < tam; i++) scanf("%d", &vetor[i]);

    //printf("[");
    //puts(vetor);
    //fputs(vetor, stdout);
    //printf("]\n");

    countingsort(vetor, tam, 25);

    /*printf("[");
    for (int i = 0; i < tam; i++) {
        if (i == tam - 1) printf("%d", vetor[i]);
        else printf("%d ", vetor[i]);
    }
    printf("]\n");*/

    //printf("\n%d\n", heapsort(vetor, tam));

    //for (int i = 0; i < tam; i++) printf("%d ", vetor[i]);

    free(vetor);

    return 0;
}
