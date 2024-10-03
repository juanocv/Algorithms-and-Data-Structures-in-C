#include <stdio.h>
#include <stdlib.h>

/*int min_max_heap(int *v, int n){
    int res = 2;
    int i;

    for (i = 0; i <= (n-2)/2; i++) {
        if (v[2*i + 1] > v[i])
            res = 0;
        if ((v[2*i + 2] < n) && (v[2*i + 2] > v[i]))
            res = 0;
    }

    if (res == 2) return 2;

    for (i = 0; i <= (n-2)/2; i++) {
        if (v[2*i + 1] < v[i])
            res = -1;
        if ((v[2*i + 2] < n) && (v[2*i + 2] < v[i]))
            res = -1;
    }

    if (res == 0) return 1;
    return 0;
}

int main() {
    int tam;
    scanf("%d", &tam);

    int *vetor = malloc(sizeof(int)*tam);
    for (int i = 0; i < tam; i++) scanf("%d", &vetor[i]);

    if (max_heap(vetor, tam) == 1)
    printf("%d\n", min_max_heap(vetor, tam));

    free(vetor);

    return 0;
}

int main() {
    int num1, soma = 1;

    scanf("%d", &num);

    for(int i = 2; i < num; i++){
        if (num % i == 0) soma+=i;
    }

    printf("%d", soma);

    return 0;
}*/

int main() {
    // declaração de variáveis
    int tam;

    printf("Tamanho do vetor de inteiros desejados: ");
    scanf("%d", &tam);

    // aloca memória para o vetor
    int *vetor = malloc(sizeof(int)*tam);

    // leitura dos valores
    for (int i = 0; i < tam; i++) {
        printf("Leitura da posicao %d: ", i+1);
        scanf("%d", &vetor[i]);
    }

    // percorre o vetor em 2D para reposicionar em ordem crescente
    for (int i = 0; i < tam; i++){
        for (int j = 0; j < tam; j++){
            if (vetor[i] < vetor[j]){
                int aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux;
            }
        }
    }

    // imprime resultados em tela
    printf("\nEm ordem crescente: ");
    for (int i = 0; i < tam; i++) {
        if (i == tam-1) printf("%d", vetor[i]);
        else printf("%d, ", vetor[i]);
    }

    // libera memória do vetor e encerra execução
    free(vetor);
    return 0;
}
