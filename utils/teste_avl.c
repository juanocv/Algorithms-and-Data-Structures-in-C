#include <stdio.h>
#include <stdlib.h>

typedef struct NoArvore NoArvore;
struct NoArvore {
    int chave;
    int altura;
    NoArvore *esq, *dir;
};

void liberar_arvore(NoArvore *raiz) {
    if (raiz == NULL) return;
    liberar_arvore(raiz->esq);
    liberar_arvore(raiz->dir);
    printf("%d ",raiz->chave);
    free(raiz);
}

/*void free_tree(NoArvore *raiz){
    if (raiz == NULL) return;
    free_tree(raiz->esq);
    free_tree(raiz->dir);
    free(raiz);
}

void pos_ordem (NoArvore* a){
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

int calc_altura(NoArvore *raiz){
    if (raiz == NULL) return -1;
    else {
        int alt_esq = calc_altura(raiz->esq);
        int alt_dir = calc_altura(raiz->dir);

        if (alt_esq > alt_dir) return (alt_esq + 1);
        else return (alt_dir + 1);
    }
}

int altura(NoArvore *raiz){
    if (raiz == NULL) return 0;
    return(calc_altura(raiz));
}*/

int altura(NoArvore *raiz){
    if (raiz == NULL) return -1;
    return raiz->altura;
}

int esta_balanceada(NoArvore *raiz){
    int fb = (altura(raiz->esq) - altura(raiz->dir));
    return ((fb > 1 || fb < -1) ? 0 : 1); // se fb > 1 ou < -1, retornar 0, else, retorne 1
}

void busca_desbalanc(NoArvore *raiz, int chave_busca, int *aux, int *printed){
    if (raiz == NULL) return;
    if (chave_busca == raiz->chave){
        if (*aux == 0){ // árvore vazia; nó a ser inserido é o primeiro
            *printed = 1;
        }
        return; // quando encontrado o nó e aux != 0, retorna para o antecessor alterando printed
    }
    // percorre a árvore e altera aux;
    else if (chave_busca < raiz->chave){
        *aux+=1;
        busca_desbalanc(raiz->esq, chave_busca, aux, printed);
    }
    else{
        *aux+=1;
        busca_desbalanc(raiz->dir, chave_busca, aux, printed);
    }

    //verificações
    if(esta_balanceada(raiz) == 1 && *printed != -1) *printed=1;
    else if (esta_balanceada(raiz) == 0){
        *printed = -1;
        printf("[No desbalanceado: %d]\n", raiz->chave);
    }
}

NoArvore *busca_no(NoArvore *raiz, int chave_busca) {
    if (raiz == NULL) return NULL;
    if (chave_busca == raiz->chave) return raiz;

    else if (chave_busca < raiz->chave)
        return busca_no(raiz->esq, chave_busca);
    else
        return busca_no(raiz->dir, chave_busca);
}

int maior(int i1, int i2){
    return(i1 > i2 ? i1 : i2);
}

NoArvore *insert(NoArvore *raiz, int chave_nova){
    if (raiz == NULL) {
    NoArvore *novo_no = malloc(sizeof(NoArvore));
    novo_no->chave = chave_nova;
    novo_no->altura = 0;
    novo_no->esq = NULL;
    novo_no->dir = NULL;
    return novo_no;
    }
    if (chave_nova < raiz->chave)
        raiz->esq = insert(raiz->esq, chave_nova);
    else if (chave_nova > raiz->chave)
        raiz->dir = insert(raiz->dir, chave_nova);

    raiz->altura = 1 + maior(altura(raiz->esq), altura(raiz->dir));

    return raiz;
}

NoArvore *inserir(NoArvore *raiz, int chave_nova) {
    int aux = 0, printed = 0;
    printf("Inserir:%d\n", chave_nova);
    if (busca_no(raiz, chave_nova) == NULL){
        raiz = insert(raiz, chave_nova);
    }
    busca_desbalanc(raiz, chave_nova, &aux, &printed);
    if (printed == 1) printf("[Ja esta balanceada]\n");
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
				int valor;
				scanf("%d", &valor);
				raiz = inserir(raiz, valor);
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


