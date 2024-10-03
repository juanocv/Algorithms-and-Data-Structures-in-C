#include <stdio.h>
#include <stdlib.h>

typedef struct ItemVetor ItemVetor;
struct ItemVetor {
    char *modelo;
    char *planeta;
    int autonomia;
};

int comparar(ItemVetor item1, ItemVetor item2) {

    //Itens com menor valor de "autonomia" devem vir antes;
    if (item1.autonomia < item2.autonomia) return -1; //item1.autonomia é menor do que item2.autonomia
    else if (item1.autonomia > item2.autonomia) return 1; //item2.autonomia é menor do que item1.autonomia

    //Empate no campo autonomia;
    if (item1.planeta[0] < item2.planeta[0]) return -1; //item1.planeta vem antes que item2.planeta na ordem alfabetica crescente
    else if (item1.planeta[0] > item2.planeta[0]) return 1; //item2.planeta vem antes que item1.planeta na ordem alfabetica crescente

    //Empate nos campos "autonomia" e "planeta".
    for(int i = 5; item1.modelo[i] != '\0' || item2.modelo[i] != '\0'; i++){
        if(item1.modelo[i] == '\0') return -1; //item1.modelo é vazio neste índice e item2.modelo não, portanto item1.modelo vem antes
        if(item2.modelo[i] == '\0') return 1; //item2.modelo é vazio neste índice e item1.modelo não, portanto item2.modelo vem antes

        if (item1.modelo[i] < item2.modelo[i]) return -1; //item1.modelo vem antes que item2.modelo na ordem alfabetica crescente
        else if (item1.modelo[i] > item2.modelo[i]) return 1; //item2.modelo vem antes que item1.modelo na ordem alfabetica crescente
    }

    int j = 0;
    return j;
}

int ordenar_vetor(ItemVetor v[], int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if(comparar(v[i], v[j]) == -1){
                ItemVetor aux = v[j];
                v[j] = v[i];
                v[i] = aux;
            }
        }
    }
}


int main(){
    ItemVetor item[4];

    item[0].modelo = "DiscoC40";
    item[0].planeta = "Marte";
    item[0].autonomia = 25;

    item[1].modelo = "DiscoC30";
    item[1].planeta = "Marte";
    item[1].autonomia = 25;

    item[2].modelo = "DiscoC20";
    item[2].planeta = "Marte";
    item[2].autonomia = 25;

    item[3].modelo = "DiscoC10";
    item[3].planeta = "Marte";
    item[3].autonomia = 25;

    ordenar_vetor(item, 4);
    //for(int i = 0; i < 4; i++) printf("%s ", item[i].modelo);
    return 0;
}
