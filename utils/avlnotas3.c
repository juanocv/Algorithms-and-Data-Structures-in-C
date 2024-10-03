#include <stdio.h>
#include <stdlib.h>
typedef struct NoArvore NoArvore;
struct NoArvore {
    int chave;
    int nota;
    int altura;
    NoArvore *esq, *dir;
};

int altura(NoArvore *raiz){
    if(raiz==NULL)
        return -1;
    else
        return raiz->altura;

}

int calcula_fb(NoArvore *raiz){
    return (altura(raiz->esq)-altura(raiz->dir));
}

int maior(int v1, int v2){
    return (v1>v2 ? v1 : v2);
}


NoArvore *buscar_aux(NoArvore *raiz, int chave, int *comp){
    if(raiz==NULL) return NULL;
    if(chave==raiz->chave){
         (*comp)++;
        return raiz;
    }else if(chave<raiz->chave){
        (*comp)++;
        return buscar_aux(raiz->esq,chave,comp);
    }else{
        (*comp)++;
        return buscar_aux(raiz->dir,chave,comp);
    }

}

void *buscar(NoArvore *raiz, int valor){
    int cont = 0;
    raiz = buscar_aux(raiz, valor, &cont);
    int nota = -1;
    if (raiz != NULL) nota = raiz->nota;
    printf("C=%d Nota=%d\n", cont, nota);
}

int get_min(NoArvore *raiz){
    if(raiz->esq==NULL)
        return raiz->chave;
    else
        return get_min(raiz->esq);
}


NoArvore *rotaciona_direita(NoArvore *raiz){
    NoArvore *filho_esq=raiz->esq;
    NoArvore *filho_esq_dir=filho_esq->dir;

    raiz->esq = filho_esq_dir;
    filho_esq->dir=raiz;
    raiz->altura=1+maior(altura(raiz->esq),altura(raiz->dir));
    filho_esq->altura = 1 + maior(altura(filho_esq->esq), altura(filho_esq->dir));

    return filho_esq;
}

NoArvore *rotaciona_esquerda(NoArvore *raiz){
    NoArvore *filho_dir=raiz->dir;
    NoArvore *filho_dir_esq=filho_dir->esq;

    raiz->dir = filho_dir_esq;
    filho_dir->esq=raiz;
    raiz->altura=1+maior(altura(raiz->esq),altura(raiz->dir));
	filho_dir->altura = 1 + maior(altura(filho_dir->esq), altura(filho_dir->dir));

    return filho_dir;
}

NoArvore *balancear(NoArvore *raiz, int *rot){

    int fb=calcula_fb(raiz);
    if(fb>1){
        (*rot)=1;
        printf("[No desbalanceado: %d]\n",raiz->chave);
        if(calcula_fb(raiz->esq)<0){
            printf("[Rotacao: DD]\n");
            raiz->esq=rotaciona_esquerda(raiz->esq);
        }else{
             printf("[Rotacao: SD]\n");
        }
        raiz=rotaciona_direita(raiz);
        printf("[x=%d y=%d z=%d]\n",raiz->esq->chave,raiz->chave,raiz->dir->chave);
    }

    if(fb<-1){
        (*rot)=1;
        printf("[No desbalanceado: %d]\n",raiz->chave);
        if(calcula_fb(raiz->dir)>0){
            printf("[Rotacao: DE]\n");
            raiz->dir=rotaciona_direita(raiz->dir);
        }else{
            printf("[Rotacao: SE]\n");
        }
        raiz=rotaciona_esquerda(raiz);

        printf("[x=%d y=%d z=%d]\n",raiz->esq->chave,raiz->chave,raiz->dir->chave);
    }


    return raiz;
}

NoArvore *remover(NoArvore *raiz, int chave, int *rot){

    if(raiz==NULL) return NULL;
    if(chave < raiz->chave){
        raiz->esq = remover(raiz->esq, chave,rot);
    }else if(chave > raiz->chave){
        raiz->dir = remover(raiz->dir, chave,rot);
    }else{

        if(raiz->esq==NULL && raiz->dir==NULL){
            free(raiz);
            return NULL;
        }

        if(raiz->esq==NULL){
            NoArvore *arvDir=raiz->dir;
            free(raiz);
            return arvDir;
        }

        if(raiz->dir==NULL){
            NoArvore *arvEsq=raiz->esq;
            free(raiz);
            return arvEsq;
        }

         int sucessor=get_min(raiz->dir);
         raiz->chave=sucessor;
         raiz->dir= remover(raiz->dir, raiz->chave,rot);
    }

    raiz->altura= 1+maior(altura(raiz->esq),altura(raiz->dir));

    return balancear(raiz,rot);
}

NoArvore *inserir_aux(NoArvore *raiz, int valor, int nota, int *rot){

    if(raiz==NULL){
        NoArvore *novo_no=malloc(sizeof(NoArvore));
        novo_no->chave=valor;
        novo_no->altura=0;
        novo_no->nota=nota;
        novo_no->dir=NULL;
        novo_no->esq=NULL;
        return novo_no;
    }
    if(valor < raiz->chave){
        raiz->esq=inserir_aux(raiz->esq, valor,nota,rot);
    }else if(valor > raiz->chave){
        raiz->dir=inserir_aux(raiz->dir, valor,nota,rot);
    }else{
        raiz->nota=nota;

        return raiz;
    }

    raiz->altura= 1+maior(altura(raiz->esq),altura(raiz->dir));

    return balancear(raiz,rot);
}

void liberar_arvore(NoArvore *raiz){

    if(raiz==NULL) return;
    liberar_arvore(raiz->esq);
    liberar_arvore(raiz->dir);
    free(raiz);
}

void pos_ordem(NoArvore *raiz){
    if(raiz==NULL) return;
    pos_ordem(raiz->esq);

    pos_ordem(raiz->dir);
    printf("%d ",raiz->chave);
}

int main() {

    NoArvore *raiz = NULL;
	char operacao;
	do {
		scanf(" %c", &operacao);
		switch (operacao) {
			case 'I' : {
				int valor,nota;
				scanf("%d", &valor);
				scanf("%d", &nota);
				int rot=0;
				raiz = inserir_aux(raiz, valor,nota,&rot);

				if(rot==0){
                    printf("[Ja esta balanceado]\n");
                }

				break;
			}
			case 'A' : {
				printf("A=%d\n", altura(raiz));
				break;
			}

			case 'B':{
				int valor;
				scanf("%d", &valor);
                buscar(raiz, valor);
                break;
			}

			case 'R':{
			    int valor;
				scanf("%d", &valor);
				int rot;
                raiz=remover(raiz, valor,&rot);

				if(rot==0){
                    printf("[Ja esta balanceado]\n");
                }

                break;

			}

			case 'P' : {
				printf("[");
				pos_ordem(raiz);
				liberar_arvore(raiz);
				printf("]\n");
				break;
			}
		}
	} while (operacao != 'P');


    return 0;
}
