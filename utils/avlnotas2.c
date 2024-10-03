#include <stdio.h>
#include <stdlib.h>

typedef struct NoArvore NoArvore;
struct NoArvore
{
   int RA;
   int nota;
   int altura;
   NoArvore *esq,*dir;
};

int altura(NoArvore *n) {
    if( n == NULL) return -1;
    else return n->altura;
}

int maior (int x, int y){
    if(x>y) return x;
    else return y;
}

int calc_fb(NoArvore *raiz){
    return(altura(raiz->esq) - altura(raiz->dir));
}

int get_min(NoArvore *raiz, int *nota){
    if(raiz->esq == NULL){
        *nota=raiz->nota;
        return raiz->RA;
    }
    else{
        return get_min(raiz->esq, nota);
    }
}

void check_bal(NoArvore *raiz, int RA, int *flag){
    if(raiz == NULL) return;
    if(calc_fb(raiz) <-1 || calc_fb(raiz)>1) *flag=1;
    if(raiz->RA == RA)
        return;
    else if(RA < raiz->RA)
        return check_bal(raiz->esq, RA, flag);
    else if(RA > raiz->RA)
        return check_bal(raiz->dir, RA, flag);
}

NoArvore *rotaciona_direita(NoArvore *raiz){
    NoArvore *filho_esq= raiz->esq;
    NoArvore *filho_esq_dir=filho_esq->dir;

    printf("y=%d z=%d]\n",raiz->RA, filho_esq->RA);

    raiz->esq = filho_esq_dir;
    filho_esq_dir=raiz;

    raiz->altura= 1 + maior(altura(raiz->esq), altura(raiz->dir));
    filho_esq->altura = 1 + maior(altura(filho_esq->esq), altura(filho_esq->dir));

    return filho_esq;
}

NoArvore *rotaciona_esquerda(NoArvore *raiz){
    NoArvore *filho_dir= raiz->dir;
    NoArvore *filho_dir_esq=filho_dir->esq;

    raiz->dir = filho_dir_esq;
    filho_dir_esq=raiz;

    raiz->altura= 1 + maior(altura(raiz->esq), altura(raiz->dir));
    filho_dir->altura = 1 + maior(altura(filho_dir->esq), altura(filho_dir->dir));

    return filho_dir;
}

NoArvore *balancear(NoArvore *raiz){
    int fb= calc_fb(raiz);
    if(fb>1){
        if(calc_fb(raiz->esq) < 0){
            raiz->esq= rotaciona_esquerda(raiz->esq);
            printf("[Rotacao: DD]\n");
            printf("[x=%d ",raiz->RA);
        }
        else{
            printf("[Rotacao: SD]\n");
        }
        raiz = rotaciona_direita(raiz);
    }
    if(fb<-1){
        if(calc_fb(raiz->dir) > 0){
            raiz->dir= rotaciona_direita(raiz->dir);
            printf("[Rotacao: DE]\n");
        }
        else{
            printf("[Rotacao: SE]\n");
        }
        raiz = rotaciona_esquerda(raiz);
    }
    return raiz;
}

NoArvore *inserir2(NoArvore *raiz, int RA, int nota){
    if(raiz == NULL){
        NoArvore *novo= malloc(sizeof(NoArvore));
        novo->RA=RA;
        novo->nota=nota;
        novo->altura=0;
        novo->esq=NULL;
        novo->dir=NULL;
        return novo;
    }
    if(RA < raiz->RA)
        raiz->esq=inserir2(raiz->esq,RA, nota);
    else if (RA > raiz->RA)
        raiz->dir=inserir2(raiz->dir,RA, nota);
    else
        raiz->nota=nota;

    raiz->altura = 1 + maior(altura(raiz->esq),altura(raiz->dir));

    if(calc_fb(raiz) <-1 || calc_fb(raiz)>1)
        printf("[No desbalanceado: %d]\n",raiz->RA);

    return raiz;
}

NoArvore *inserir(NoArvore *raiz, int RA, int nota) {
    int flag=0;
    NoArvore *aux = inserir2(raiz,RA, nota);
    check_bal(aux,RA,&flag);
    if(flag == 0)
        printf("[Ja esta balanceado]\n");
    else
        aux= balancear(aux);
    return aux;
}

NoArvore *remover2(NoArvore *raiz, int RA){
    if(raiz == NULL) return NULL;
    if(RA < raiz->RA)
        return remover2(raiz->esq, RA);
    else if(RA > raiz->RA)
        return remover2(raiz->dir,RA);
    else{
        if(raiz->esq == NULL){
            NoArvore *arvDir=raiz->dir;
            free(raiz);
            return arvDir;
        }
        if(raiz->dir == NULL){
            NoArvore *arvEsq=raiz->esq;
            free(raiz);
            return arvEsq;
        }
        int nota;
        int sucessor = get_min(raiz->dir, &nota);
        raiz->RA= sucessor;
        raiz->nota=nota;
        raiz->dir= remover2(raiz->dir, sucessor);
    }

    raiz->altura= 1 + maior(altura(raiz->esq), altura(raiz->dir));
    return raiz;
}

NoArvore *remover(NoArvore *raiz, int RA){
    int flag=0;
    NoArvore *aux = remover2(raiz,RA);
    check_bal(aux,RA,&flag);
    if(flag == 0)
        printf("[Ja esta balanceado]\n");
    else
       aux= balancear(aux);
    return aux;
}
void buscar(NoArvore *raiz, int RA, int *C, int *nota){
    if(raiz == NULL)return ;
    if(raiz->RA == RA) {
        *nota = raiz->nota;
        (*C)++;
    }
    if(raiz->RA < RA){
        (*C)++;
        return buscar(raiz->dir, RA, C, nota);
    }
    else if(raiz->RA > RA){
        (*C)++;
        return buscar(raiz->dir, RA, C, nota);
    }
}

void liberar_arvore(NoArvore *raiz) {
    if(raiz == NULL) return;
    liberar_arvore(raiz->esq);
    liberar_arvore(raiz->dir);
    printf("%d ", raiz->RA);
    free(raiz);
}

int main() {
    NoArvore *raiz = NULL;
    int RA, nota;
	char operacao;
	do {
		scanf(" %c", &operacao);
		switch (operacao) {
			case 'I' : {
				scanf("%d %d", &RA, &nota);
				raiz = inserir(raiz, RA, nota);
				break;
			}
            case 'R' : {
                scanf("%d",&RA);
                raiz= remover(raiz, RA);
                break;
            }
			case 'A' : {
				printf("A=%d\n", altura(raiz));
				break;
			}
            case 'B' :{
                scanf("%d", &RA);
                int C=0;
                nota=-1;
                buscar(raiz, RA, &C, &nota);
                if(nota == -1)
                    printf("C=%d Nota=-1\n",C);
                else
                    printf("C=%d Nota=%d\n",C,nota);
                break;
            }
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
