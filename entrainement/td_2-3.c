#include <stdio.h>

#define VMAX 20000

int main() {
    int V, S, tab[VMAX];
    scanf("%d", &V);
    scanf("%d", &S);

    int i=0;
    while(i<V) tab[i++] = 0;

    // Tant que S<V et qu'on est pas déjà passés sur cette case (sinon boucle infinie)
    // On teste les trois opérations une par une, jusqu'à qu'une donne un résultat cohérent
    // Ensuite on va à cette case et on teste...
    while(S<=V && tab[S] != 1) {
        tab[S] = 1;

        if(3*S<=V)          S *= 3;
        else if (2*S<=V)    S *= 2;
        else                S /= 5;
    }

    // On prend la plus grande case qui a un 1, ie qui est atteignable par le process
    i=V;
    while(i>0) {
        if(tab[i--]==1) {
            printf("%d\r\n", i+1);
            break;
        }
    }

    return 0;
}