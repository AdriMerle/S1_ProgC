#include <stdio.h>

#define MAX_SIZE 1000
#define MAX_NB_OBJ 100

int sac(int tab[MAX_NB_OBJ][MAX_SIZE], int obj[], int i_size, int j_obj) {
    if(j_obj>=0 && i_size-obj[j_obj]>=0) {
        if (tab[j_obj][i_size]==1) {
            return 1;
        } else if (sac(tab, obj, i_size, j_obj-1)==1) {
            return 1;
        } else if (sac(tab, obj, i_size-obj[j_obj], j_obj-1)==1) {
            return 1;
        } else return 0;
    } else return 0;
}


int main() {
    int tab[MAX_NB_OBJ][MAX_SIZE], obj[MAX_NB_OBJ], capacite, input, nb_obj=0, i=0;

    scanf("%d", &capacite);
    scanf("%d", &input);

    while(input!=-1 && nb_obj<=MAX_NB_OBJ) {
        obj[nb_obj++] = input;
        scanf("%d", &input);
    }
    
    tab[0][0] = 1;
    while(i<nb_obj) {
        tab[i][obj[i]] = 1;
        i++;
    }

    if (sac(tab, obj, capacite, nb_obj-1)==1)   printf("OUI\r\n");
    else printf("NON\r\n");

    return 0;
}