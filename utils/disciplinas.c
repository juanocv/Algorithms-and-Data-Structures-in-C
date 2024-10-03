#include <stdio.h>
#include <stdlib.h>

typedef struct Disciplina Disciplina;
struct Disciplina {
    int cod;
    char *nome;
    int creditos;
    Disciplina *requisito;
};

typedef struct Curso Curso;
struct Curso {
    int cod_curso;
    char *nome_curso;
    Disciplina *ultima_disciplina;
};

void insere_disciplina(Curso *curso, Disciplina *nova_disciplina) {
    Disciplina* target_disciplina = curso->ultima_disciplina;
    Disciplina* target = NULL;
    int i = 0;

    while(nova_disciplina->nome[i]!='\0'){

        if((nova_disciplina->nome[i] < curso->ultima_disciplina->nome[i]) || (nova_disciplina->nome[i+1]=='\0' && curso->ultima_disciplina->nome[i+1]!='\0')){
            i = 0;
            do{
                if (target_disciplina == NULL){

                    target->requisito = nova_disciplina;

                    nova_disciplina->requisito = target_disciplina;

                    break;
                }
                else if ((nova_disciplina->nome[i] < target_disciplina->nome[i]) || (nova_disciplina->nome[i+1]=='\0' && target_disciplina->nome[i+1]!='\0')){
                    target = target_disciplina;

                    target_disciplina = target_disciplina->requisito;

                    i = 0;
                }
                else if (nova_disciplina->nome[i] > target_disciplina->nome[i]){

                    nova_disciplina->requisito = target_disciplina;

                    target->requisito = nova_disciplina;

                    break;
                }
                else{
                    i++;
                }

            }while(i>=0);

            break;
        }

        else if(nova_disciplina->nome[i] > curso->ultima_disciplina->nome[i]){

            if (curso->ultima_disciplina->requisito == NULL){

                nova_disciplina->requisito = curso->ultima_disciplina;

                curso->ultima_disciplina = nova_disciplina;

                break;

            }
            else{
                nova_disciplina->requisito = curso->ultima_disciplina;

                curso->ultima_disciplina = nova_disciplina;

                break;
            }
        }

        else{
            i++;
        }
    }
}

int main(){

    Disciplina d1={20,"Disciplina20",6};

    Curso curso={1,"curso",&d1};

    Disciplina d2={10,"Disciplina10",4};

    curso.ultima_disciplina->requisito=&d2;

    d2.requisito=NULL;

    Disciplina d3={99,"Disciplina21",1};

    insere_disciplina(&curso,&d3);

    Disciplina* p=curso.ultima_disciplina;

    do{
        printf("cod=%d nome=%s creditos=%d\n",p->cod, p->nome,p->creditos);
        p=p->requisito;
    }while (p);

    return 0;
}
