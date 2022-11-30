#include <stdio.h>

#define MAXSIZE 1000
#define NB_MAX_OBJ 100

int sac(int tab[NB_MAX_OBJ][MAXSIZE], int objs[], int i_size, int j_obj) {
    if(j_obj>=0 && i_size-objs[j_obj]>=0) {
        if(tab[j_obj][i_size]==1)                                return 1;   // full with the new obj
        else if(sac(tab, objs, i_size, j_obj-1)==1)              return 1;   // already full without the new obj
        else if(sac(tab, objs, i_size-objs[j_obj], j_obj-1)==1)  return 1;   // sac of capacity (size-new object) is full
        else return 0;
    } else return 0;
}

int main() {
    int tab[NB_MAX_OBJ][MAXSIZE], size, objs[NB_MAX_OBJ], input, nb_objs=0, j=0;

    scanf("%d", &size);
    scanf("%d", &input);
    
    while(input!=-1 && nb_objs<NB_MAX_OBJ) {
        objs[nb_objs++] = input;
        scanf("%d", &input);
    }

    tab[0][0] = 1;
    while(j<nb_objs) {
        tab[j][objs[j]] = 1;
        j++;
    }

    if(sac(tab, objs, size, nb_objs-1)==1)  printf("OUI\r\n");
    else                                    printf("NON\r\n");

    return 0;
}