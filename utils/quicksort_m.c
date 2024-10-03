#include <stdio.h>
#include <stdlib.h>

int get_int_len (int value){
    int l=1;
    while(value>9){ l++; value/=10; }
    return l;
}

void int_to_char(int num, char *arr, int len){

    if (num == 0) arr[0] = '0';

    else{

        char arr1[len];

        int index = 0;
        while (num) {
            arr1[++index] = num % 10 + '0';
            num /= 10;
        }

        int i;
        for (i = 0; i < index; i++) {
            arr[i] = arr1[index - i];
        }

        arr[i] = '\0';
    }
}

int verificacao_ordem(char v, char pivo){
    //0 < 5 < 6 < 4 < 8 < 9 < 7 < 3 < 1 < 2
    int pivo_int = pivo - '0';
    if (v == '0' && pivo_int > 0) return 1;
    if (v == '5' && (pivo_int > 5 || (pivo_int <= 4 && pivo_int != 0))) return 1;
    if (v == '6' && (pivo_int > 6 || (pivo_int <= 4 && pivo_int != 0))) return 1;
    if (v == '4' && (pivo_int >= 7 || (pivo_int <= 3 && pivo_int != 0))) return 1;
    if (v == '8' && (pivo_int == 9 || pivo_int == 7 || (pivo_int <= 3 && pivo_int != 0))) return 1;
    if (v == '9' && (pivo_int == 7 || (pivo_int <= 3 && pivo_int != 0))) return 1;
    if (v == '7' && (pivo_int <= 3 && pivo_int != 0)) return 1;
    if (v == '3' && (pivo_int == 1 || pivo_int == 2)) return 1;
    if (v == '1' && (pivo_int == 2)) return 1;
    return 0;
}

int ordem_marciana(char *v, char *pivo, int v_len, int pivo_len, int *cmp) {
    (*cmp)++;
    if (v_len > pivo_len) return 0;
    if (v_len < pivo_len) return 1;
    for (int i = 0; v[i] != '\0'; i++) {
        if (i != v_len - 1) {
            if (verificacao_ordem(v[i], pivo[i]) == 1) return 1;
            else{
                if (v[i] == pivo[i]) continue;
                else return 0;
            }
        }
        else {
            if (verificacao_ordem(v[i], pivo[i]) == 1 ) return 1;
        }
    }

    return -1;
}

int particiona(int *v, int esq, int dir, int *comp) {
    int pivo = v[dir];

    int i, ultimo_menores = esq - 1;
    for (i = esq; i < dir; i++) {
        int v_len = get_int_len(v[i]), pivo_len = get_int_len(pivo);
        char v_str[v_len], pivo_str[pivo_len];

        int_to_char(v[i], v_str, v_len);
        int_to_char(pivo, pivo_str, pivo_len);

        if (ordem_marciana(v_str, pivo_str, v_len, pivo_len, comp) == 1) {
            ultimo_menores++;
            int tmp = v[i];
            v[i] = v[ultimo_menores];
            v[ultimo_menores] = tmp;
        }
    }

    v[dir] = v[ultimo_menores+1];
    v[ultimo_menores+1] = pivo;
    return ultimo_menores + 1;
}

void quick_sort(int *v, int esq, int dir, int *comp) {
    if (esq < dir) {
        //printf("cmp_teste: %d", *comp);
        int indice_pivo = particiona(v, esq, dir, comp);
        quick_sort(v, esq, indice_pivo - 1, comp);
        quick_sort(v, indice_pivo + 1, dir, comp);
    }
}

int quicksortm(int *v, int n){
    for(int i = 0; i < n; i++) printf("%d ", v[i]);
    int comparacoes = 0;
    quick_sort(v, 0, n - 1, &comparacoes);
    return comparacoes;
}

int main() {
    int tam = 20;
    //scanf("%d", &tam);

    //int *vetor = malloc(sizeof(int)*tam);
    int vetor[20] = {93, 4, 30, 73, 41, 87, 49, 95, 50, 49, 63, 52, 84, 78, 58, 53, 84, 89, 40, 16};
    //for (int i = 0; i < tam; i++) scanf("%d", &vetor[i]);

    //for (int i = 0; i < tam; i++) printf("%d", vetor[i]);

    printf("\n%d\n", quicksortm(vetor, tam));

    for (int i = 0; i < tam; i++) printf("%d ", vetor[i]);

    //free(vetor);

    return 0;
}
