#include <stdio.h>

#define MAX_OBJ 100
#define MAX_CAPACITE 10000

int sac(int tab[MAX_OBJ][MAX_CAPACITE], int obj[], int i_size, int j_obj) {
    if(j_obj>=0 && i_size-obj[j_obj]>=0) {
        if (tab[j_obj][i_size]==1) {
            return 1;
        } else if (sac(tab, obj, i_size, j_obj-1)==1) {
            return 1;
        } else if (sac(tab, obj, i_size-obj[j_obj], j_obj-1)) {
            return 1;
        } else {
            return 0;
        }
    } else {
        return 0;
    }
}

int main() {
    int obj[MAX_OBJ], tab[MAX_OBJ][MAX_CAPACITE]={0};
    int tempEntry, capacite, nb_obj=0;
    

    scanf("%d", &capacite);
    scanf("%d", &tempEntry);

    while(tempEntry != -1 && nb_obj<=MAX_OBJ) {
        obj[nb_obj++] = tempEntry;
        //printf("OBJ : %d\r\n", tempEntry);
        scanf("%d", &tempEntry);
    }

    tab[0][0] = 1;

    // Cases (i, obj[i]) = 1
    int i=0;
    while(i<nb_obj) {
        tab[i][obj[i]] = 1;
        i++;
    }

    if (sac(tab, obj, capacite, nb_obj-1)==1) {
        printf("OUI\r\n");
    } else {
        printf("NON\r\n");
    }
}