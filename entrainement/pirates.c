/*
L'entrée standard sera composée d'une série de nombres entiers positifs séparés 
par des retours à la ligne :
- la capacité vacante du bateau 1 (entier n, 1 <= n <= 10000) ;
- la capacité vacante du bateau 2 (entier m, 1 <= m <= 10000) ;
- le nombre d’objets en argent du trésor (entier pa, 1 <= pa <= 100) ;
- le nombre d’objets en or du trésor (entier po, 1 <= po <= 100) ;
- pa+po nombres entiers positifs, représentants les poids des objets 
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10000
#define MAX_OBJ 100

// Sac a dos 2
int sac(int tab[MAX_OBJ][MAX_SIZE], int obj[], int i_size, int j_obj) {
    if(j_obj>=0 && i_size-obj[j_obj]>=0) {
        if(tab[j_obj][i_size]==1) return 1;
        else if (sac(tab, obj, i_size, j_obj-1)==1) return 1;
        else if (sac(tab, obj, i_size-obj[j_obj], j_obj-1)==1) return 1;
        else return 0;
    } else return 0;
}


// Calcule la taille max qu'il est possible de remplir
int bateau(int tab[MAX_OBJ][MAX_SIZE], int obj[], int size, int nb_obj) {
    int i=0;
    while((size-i>0) && (sac(tab, obj, size-i, nb_obj)!=1)) {
        i++;
    }
    return size-i;
}


int main() {
    int size1, size2;
    int nb_or, nb_arg;
    int o_or[MAX_OBJ], o_arg[MAX_OBJ];
    int t_or[MAX_OBJ][MAX_SIZE], t_arg[MAX_OBJ][MAX_SIZE];

    // INPUTS

    fscanf(stdin, "%d", &size1);
    fscanf(stdin, "%d", &size2);
    fscanf(stdin, "%d", &nb_arg);
    fscanf(stdin, "%d", &nb_or);

    int i=0;
    while(i<nb_arg) fscanf(stdin, "%d", &o_arg[i++]);
    i=0;
    while(i<nb_or) fscanf(stdin, "%d", &o_or[i++]);

    // INIT TABS
    i=0;
    t_arg[0][0] = 1;
    while(i<nb_arg) {
        t_arg[o_arg[i]][i] = 1;
        i++;
    }
    
    i=0;
    t_or[0][0] = 1;
    while(i<nb_or) {
        t_or[o_or[i]][i] = 1;
        i++;
    }


    // BATEAU 1
    int max_arg = bateau(t_arg, o_arg, size1, nb_arg-1);
    int max_or = bateau(t_or, o_or, size1, nb_or-1);
    int max_1;
    
    if(max_arg>max_or) {
        max_1 = max_arg;
    } else {
        max_1 = max_or;
    }

    // BATEAU 2
    max_arg = bateau(t_arg, o_arg, size2, nb_arg);
    max_or = bateau(t_or, o_or, size2, nb_or);
    int max_2;
    
    if(max_arg>max_or) {
        max_2 = max_arg;
    } else {
        max_2 = max_or;
    }

    printf("%d\r\n", max_1 + max_2);
}