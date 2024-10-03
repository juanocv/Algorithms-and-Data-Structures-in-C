#include <stdio.h>

typedef struct DiscoVoador DiscoVoador;
struct DiscoVoador {
    char *modelo;
    char *planeta;
    int autonomia;
};

int verificar_ordenacao(DiscoVoador *discos, int n_discos) {
    int i = 0, j = 0, k = 0, n_1 = 0, n_2 = 0, n_3 = 0, n_4 = 0;

    for (i = 0; i+1 < n_discos; i++){
        if (discos[i+1].modelo[5] > discos[i].modelo[5]){
            if (n_2 != 0){
                break;
            }
            else{
                n_1++;
            }
        }
        else if (discos[i+1].modelo[5] < discos[i].modelo[5]){
            if (n_1 != 0){
                break;
            }
            else{
                n_2++;
            }
        }
        else if (discos[i+1].modelo[5] == discos[i].modelo[5]){
            for(j = 6; discos[i].modelo[j] != '\0'; j++){
                if (discos[i+1].modelo[j] > discos[i].modelo[j]){
                    n_1++;
                    break;
                }
                else if (discos[i+1].modelo[j] < discos[i].modelo[j]){
                    n_2++;
                    break;
                }
                else{
                    if (discos[i].modelo[j+1] == '\0' && discos[i+1].modelo[j+1] != '\0'){
                        n_1++;
                        break;
                    }
                }
            }
        }
    }

    if (n_1 == n_discos-1){
        return 1;
    }
    else if (n_2 == n_discos-1){
        return 2;
    }
    else{
        for (j = 0; j+1 < n_discos; j++){
            if (discos[j+1].planeta[0] > discos[j].planeta[0]){
                n_3++;
            }
            else if (discos[j+1].planeta[0] == discos[j].planeta[0]){
                if (discos[j+1].autonomia <= discos[j].autonomia){
                    n_3++;
                }
                else{
                    break;
                }
            }
            else{
                break;
            }
        }

        if (n_3 == n_discos-1){
            return 3;
        }
        else{
            for (k = 0; k+1 < n_discos; k++){
                if (discos[k+1].autonomia > discos[k].autonomia){
                    n_4++;
                }
                else if (discos[k+1].autonomia == discos[k].autonomia){
                    if (discos[k+1].planeta[0] > discos[k].planeta[0]){
                        n_4++;
                    }
                    else if (discos[k+1].planeta[0] == discos[k].planeta[0]){
                        if (discos[k+1].modelo[5] > discos[k].modelo[5]){
                            n_4++;
                        }
                        else if (discos[k+1].modelo[5] == discos[k].modelo[5]){
                            for(j = 6; discos[k].modelo[j] != '\0'; j++){
                                if (discos[k+1].modelo[j] > discos[k].modelo[j]){
                                    n_4++;
                                    break;
                                }
                                else if (discos[k].modelo[j+1] == '\0' && discos[k+1].modelo[k+1] != '\0'){
                                    n_4++;
                                    break;
                                }
                                else{
                                    break;
                                }
                            }
                        }
                    }
                }
            }

            if (n_4 == n_discos-1){
                return 4;
            }
            else{
                return 0;
            }
        }
    }
}

int main(){
    DiscoVoador disco[20];

    disco[0].modelo = "DiscoC10";
    disco[0].planeta = "Marte";
    disco[0].autonomia = 25;

    disco[1].modelo = "DiscoC20";
    disco[1].planeta = "Marte";
    disco[1].autonomia = 25;

    disco[2].modelo = "DiscoE3";
    disco[2].planeta = "Marte";
    disco[2].autonomia = 39;

    disco[3].modelo = "DiscoD2";
    disco[3].planeta = "Marte";
    disco[3].autonomia = 49;

    disco[4].modelo = "DiscoE3B";
    disco[4].planeta = "Marte";
    disco[4].autonomia = 59;

    disco[5].modelo = "DiscoB900";
    disco[5].planeta = "Terra";
    disco[5].autonomia = 70;

    disco[6].modelo = "DiscoB90";
    disco[6].planeta = "Terra";
    disco[6].autonomia = 75;

    disco[7].modelo = "DiscoF10";
    disco[7].planeta = "Jupiter";
    disco[7].autonomia = 90;

    disco[8].modelo = "DiscoF20";
    disco[8].planeta = "Jupiter";
    disco[8].autonomia = 90;

    disco[9].modelo = "DiscoG150";
    disco[9].planeta = "Saturno";
    disco[9].autonomia = 90;

    disco[10].modelo = "DiscoG300";
    disco[10].planeta = "Saturno";
    disco[10].autonomia = 90;

    disco[11].modelo = "DiscoH1000";
    disco[11].planeta = "Netuno";
    disco[11].autonomia = 150;

    disco[12].modelo = "DiscoH200";
    disco[12].planeta = "Netuno";
    disco[12].autonomia = 150;

    disco[13].modelo = "DiscoH50";
    disco[13].planeta = "Saturno";
    disco[13].autonomia = 150;

    disco[14].modelo = "DiscoH100";
    disco[14].planeta = "Urano";
    disco[14].autonomia = 150;

    disco[15].modelo = "DiscoD1";
    disco[15].planeta = "Marte";
    disco[15].autonomia = 400;

    disco[16].modelo = "DiscoA2";
    disco[16].planeta = "Netuno";
    disco[16].autonomia = 500;

    disco[17].modelo = "DiscoA4";
    disco[17].planeta = "Terra";
    disco[17].autonomia = 500;

    disco[18].modelo = "DiscoA1";
    disco[18].planeta = "Urano";
    disco[18].autonomia = 500;

    disco[19].modelo = "DiscoA3";
    disco[19].planeta = "Urano";
    disco[19].autonomia = 500;

    int retorno_ordenacao = verificar_ordenacao(disco, 20);

    printf("%d", retorno_ordenacao);
    return 0;
}
