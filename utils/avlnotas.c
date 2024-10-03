#include <stdio.h>
#include <stdlib.h>

typedef struct NoArvore NoArvore;
struct NoArvore {
    int chave;
    int altura;
    int nota;
    NoArvore *esq, *dir;
};

void free_tree(NoArvore *raiz){
    if (raiz == NULL) return;
    free_tree(raiz->esq);
    free_tree(raiz->dir);
    free(raiz);
}

void pos_ordem (NoArvore *a){
    if (a!=NULL){
        pos_ordem(a->esq);
        pos_ordem(a->dir);
        printf("%d ",a->chave);
    }
}

void liberar_arvore(NoArvore *raiz) {
    pos_ordem(raiz);
    free_tree(raiz);
}

int altura(NoArvore *raiz){
    if (raiz == NULL) return -1;
    return raiz->altura;
}

int maior(int i1, int i2){
    return(i1 > i2 ? i1 : i2);
}

NoArvore *rotaciona_direita(NoArvore *raiz) {
    NoArvore *filho_esq = raiz->esq;
    NoArvore *filho_esq_dir = filho_esq->dir;

    raiz->esq = filho_esq_dir;
    filho_esq->dir = raiz;

    raiz->altura = 1 + maior(altura(raiz->esq), altura(raiz->dir));
    filho_esq->altura = 1 + maior(altura(filho_esq->esq), altura(filho_esq->dir));

    return filho_esq;
}

NoArvore *rotaciona_esquerda(NoArvore *raiz) {
    NoArvore *filho_dir = raiz->dir;
    NoArvore *filho_dir_esq = filho_dir->esq;

    raiz->dir = filho_dir_esq;
    filho_dir->esq = raiz;

    raiz->altura = 1 + maior(altura(raiz->esq), altura(raiz->dir));
    filho_dir->altura = 1 + maior(altura(filho_dir->esq), altura(filho_dir->dir));

    return filho_dir;
}

NoArvore *balancear(NoArvore *raiz, int *balanced){
    int fb = (altura(raiz->esq) - altura(raiz->dir));

    if ((fb > 1) || (fb < -1)){
        *balanced = 0;
        printf("[No desbalanceado: %d]\n", raiz->chave);

        if (fb > 1){
            if ((altura(raiz->esq->esq) - altura(raiz->esq->dir)) < 0) {
                printf("[Rotacao: DD]\n");
                raiz->esq = rotaciona_esquerda(raiz->esq);
            }
            else printf("[Rotacao: SD]\n");
            raiz = rotaciona_direita(raiz);
        }

        if (fb < -1){
            if ((altura(raiz->dir->esq) - altura(raiz->dir->dir)) > 0) {
                printf("[Rotacao: DE]\n");
                raiz->dir = rotaciona_direita(raiz->dir);
            }
            else printf("[Rotacao: SE]\n");
            raiz = rotaciona_esquerda(raiz);
        }

        printf("[x=%d y=%d z=%d]\n", raiz->esq->chave, raiz->chave, raiz->dir->chave);
    }

    return raiz;
}

NoArvore *insert(NoArvore *raiz, int chave_nova, int nota, int *balance){
    if (raiz == NULL) {
    NoArvore *novo_no = malloc(sizeof(NoArvore));
    novo_no->chave = chave_nova;
    novo_no->altura = 0;
    novo_no->nota = nota;
    novo_no->esq = NULL;
    novo_no->dir = NULL;
    return balancear(novo_no, balance);
    }

    if (chave_nova < raiz->chave)
        raiz->esq = insert(raiz->esq, chave_nova, nota, balance);
    else if (chave_nova > raiz->chave)
        raiz->dir = insert(raiz->dir, chave_nova, nota, balance);

    raiz->altura = 1 + maior(altura(raiz->esq), altura(raiz->dir));

    return balancear(raiz, balance);
}

NoArvore *busca_no(NoArvore *raiz, int chave_busca, int *comp) {
    if (raiz == NULL) return NULL;
    *comp+=1;
    if (chave_busca == raiz->chave) return raiz;

    else if (chave_busca < raiz->chave)
        return busca_no(raiz->esq, chave_busca, comp);
    else
        return busca_no(raiz->dir, chave_busca, comp);
}

NoArvore *inserir(NoArvore *raiz, int chave, int nota){
    int dummy = 0, balanced = 1;
    NoArvore *no = busca_no(raiz, chave, &dummy);
    if (no == NULL) raiz = insert(raiz, chave, nota, &balanced);
    else no->nota = nota;

    if(balanced == 1) printf("[Ja esta balanceado]\n");
    return raiz;
}

NoArvore *get_min(NoArvore *raiz){
    return(raiz->esq == NULL ? raiz : get_min(raiz->esq));
}

NoArvore *remover_chave(NoArvore *raiz, int chave, int *balanced) {
    if (raiz == NULL) return NULL;
    if (chave < raiz->chave)
        raiz->esq = remover_chave(raiz->esq, chave, balanced);
    else if (chave > raiz->chave)
        raiz->dir = remover_chave(raiz->dir, chave, balanced);
    else {
        if (raiz->esq == NULL) {
            NoArvore *arvDir = raiz->dir;
            free(raiz);
            return arvDir;
        }
        if (raiz->dir == NULL) {
            NoArvore *arvEsq = raiz->esq;
            free(raiz);
            return arvEsq;
        }
        NoArvore *sucessor = get_min(raiz->dir);
        raiz->chave = sucessor->chave;
        raiz->nota = sucessor->nota;
        raiz->dir = remover_chave(raiz->dir, raiz->chave, balanced);
    }

    raiz->altura = 1 + maior(altura(raiz->esq), altura(raiz->dir));

    return balancear(raiz, balanced);
}

NoArvore *remover(NoArvore *raiz, int chave){
    int dummy = 0, balanced = 1;
    NoArvore *no = busca_no(raiz, chave, &dummy);
    if (no != NULL) raiz = remover_chave(raiz, chave, &balanced);
    else raiz = balancear(raiz, &balanced);

    if(balanced == 1) printf("[Ja esta balanceado]\n");
    return raiz;
}

int main() {
	NoArvore *raiz = NULL;
	char operacao;
	do {
		scanf(" %c", &operacao);
		switch (operacao) {
		    //I (número): inserir número na árvore
			case 'I' : {
				int ra, nota;
				scanf("%d\n%d", &ra, &nota);
				raiz = inserir(raiz, ra, nota);
				break;
			}
			//R (número): remover número na árvore
			case 'R' : {
                int ra;
                scanf("%d", &ra);
                raiz = remover(raiz, ra);
                break;
			}
			//B: busca nó com número informado
			case 'B' : {
			    int ra, cmp = 0;
			    scanf("%d", &ra);
			    NoArvore *no_nota = busca_no(raiz, ra, &cmp);
			    if (no_nota == NULL) {
                    printf("C=%d Nota=%d\n", cmp, -1);
			    }
			    else {
                    printf("C=%d Nota=%d\n", cmp, no_nota->nota);
			    }
				break;
			}
			//A: obter altura da árvore
			case 'A' : {
				printf("A=%d\n", altura(raiz));
				break;
			}
			//P: imprimir árvore no percurso pós-ordem e liberar árvore da memória
			case 'P' : {
				printf("[");
				liberar_arvore(raiz);
				printf("]\n");
				break;
			}
		}
	} while (operacao != 'P');

	return 0;
}
