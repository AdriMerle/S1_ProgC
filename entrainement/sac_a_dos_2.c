#include <stdio.h>

#define MAX_SIZE 10000
#define MAX_OBJ 100

int sac(int tab[MAX_OBJ][MAX_SIZE], int obj[], int i_size, int j_obj) {
    if(j_obj>=0 && i_size-obj[j_obj]>=0) {
        if(tab[j_obj][i_size]==1) return 1;
        else if (sac(tab, obj, i_size, j_obj-1)==1) return 1;
        else if (sac(tab, obj, i_size-obj[j_obj], j_obj-1)==1) return 1;
        else return 0;
    } else return 0;
}

int main() {
    int tab[MAX_OBJ][MAX_SIZE], obj[MAX_OBJ], size, i=0, input, nb_obj=0;

    scanf("%d", &size);
    scanf("%d", &input);
    
    while(input!=-1 && nb_obj<MAX_OBJ) {
        obj[nb_obj++] = input;
        scanf("%d", &input);
    }

    // Remplir tab
    tab[0][0] = 1;
    while(i<nb_obj) {
        tab[i][obj[i]] = 1;
        i++;
    }

    if(sac(tab, obj, size, nb_obj)==1)    printf("OUI\r\n");
    else            printf("NON\r\n");

    return 0;
}