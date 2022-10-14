#include <stdio.h>

#define MAXSIZE 1000
#define MAXOBJ 100

int main() {
    int objs[MAXOBJ], j, nb_obj;
    int tab[MAXSIZE], i, tailleMax;

    // Reading stuff
    scanf("%d", &tailleMax);

    int keepon=1, tempEntry, a=0;
    while(keepon==1) {
        scanf("%d", &tempEntry);
        if(tempEntry > 0) {
            objs[a++] = tempEntry;
        } else {
            nb_obj = a;
            keepon = 0;
        }
    }

    // Print 
    printf("Size max = %d \r\nObjs : ", tailleMax);
    for(int a=0; a<nb_obj; a++) {
        printf("%d ", objs[a]);
    }
    printf("\r\n");

    tab[0] = 1;
    

    // i = taille du sac
    // j = indice de l'objet
    i = 1, j=0;

    while(i<=tailleMax) {
        j=0;
        while(j<nb_obj) {
            if (i-objs[j] >= 0 && tab[i-objs[j]]==1) {
                tab[i] = 1;
                j=nb_obj;
            } else tab[i] = 0;
            j++;
        }
        i++;
    }
    /*
    // PRINT
    printf("TAB = ");
    for(int a=0; a<=tailleMax; a++) {
        printf("%d ", tab[a]);
    }
    printf("\r\n");

    */

    if(tab[tailleMax]==1)   printf("OUI");
    else                    printf("NON");
    return 0;
}