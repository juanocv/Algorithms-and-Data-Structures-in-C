#include <stdio.h>
#include <stdlib.h>

typedef struct Disciplina Disciplina;
struct Disciplina {
    int cod;
    char *nome;
    int creditos;
    Disciplina *requisito;
};

Disciplina *requisito_inicial(Disciplina *disciplina, int *qtd) {
    Disciplina *req_inic = NULL;
    int count = 0;
    *qtd = 0;

    if(disciplina->requisito == NULL){
        return NULL;
    }

    for(; disciplina->requisito != NULL; count++){
        req_inic = disciplina->requisito;
        disciplina = req_inic;
    }

    *qtd = count;
    return req_inic;
}

int main(){
    int qtd_disc, i;

    scanf("%d", &qtd_disc);

    Disciplina p[qtd_disc], *res = malloc(sizeof(Disciplina));

    for(;i<qtd_disc;i++){
        if(i==0){
            scanf("%d %d", &p[i].cod, &p[i].creditos);
            p[i].nome = "Analise_1";
            printf("%d %s %d\n", p[i].cod, p[i].nome, p[i].creditos);
            p[i].requisito = NULL;
        }
        else{
            scanf("%d %d", &p[i].cod, &p[i].creditos);
            p[i].nome = "Analise_2";
            p[i].requisito = malloc(sizeof(struct Disciplina));
            p[i].requisito->cod = p[i-1].cod;
            p[i].requisito->nome = p[i-1].nome;
            p[i].requisito->creditos = p[i-1].creditos;
            p[i].requisito->requisito = p[i-1].requisito;
            printf("%d %s %d\n%d %s %d\n", p[i].cod, p[i].nome, p[i].creditos,
                   p[i].requisito->cod, p[i].requisito->nome, p[i].requisito->creditos);
        }
    }

    res = requisito_inicial(p, &qtd_disc);
    printf("%d %s %d\n", res->cod, res->nome, res->creditos);
    printf("Quantidade de requisitos: %d", qtd_disc);

    free(p[i].requisito);
    free(res);
    return 0;
}
