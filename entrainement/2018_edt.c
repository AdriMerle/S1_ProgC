#include <stdio.h>

#define MAX_TACHES 80
#define MAX_DUREE 2000

int sac(int tab[MAX_DUREE][MAX_TACHES], int obj[], int i_size, int j_obj) {
    if(j_obj>=0 && i_size-obj[j_obj]>=0) {
        if(tab[i_size][j_obj]==1) return 1;
        else if(sac(tab, obj, i_size, j_obj-1)==1) return 1;
        else if(sac(tab, obj, i_size-obj[j_obj], j_obj-1)==1) return 1;
        else return 0;
    } else {
        return 0;
    }
}

int main() {
    int tA[MAX_TACHES], tB[MAX_TACHES], tabB[MAX_DUREE][MAX_TACHES], tabAB[MAX_DUREE][MAX_TACHES*2];
    int duree, nb_taches, i=0, j=0, n1, n2;


    // INPUT
    scanf("%d", &duree);
    scanf("%d", &nb_taches);

    while(i+j<nb_taches) {
        fscanf("%d %d", &n1, &n2);
        if(n1==1) {
            tA[i] = n2;
            i++;
        } else {
            tB[j] = n2;
            j++;
        }
    }

    // Filling our tabs

    // Test with only TypeB (tB)
    if(sac(tabB, tB, duree, i)==1) {
        printf("0\r\n");
    }

    return 1;
}