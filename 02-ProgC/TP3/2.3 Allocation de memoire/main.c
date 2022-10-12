#include <stdio.h>
#include <stdlib.h>
#include "biblio.h"

int main() {
    int *tab, count=0, tabLength=2, number, nbtokens;
    int *newTab;

    tab = malloc(tabLength*sizeof(int));

    while(1) {
        nbtokens = scanf("%d", &number);

        if(nbtokens != 1 || feof(stdin)) break;

        if(count<tabLength) tab[count] = number;
        else {
            tabLength *= 2;
            newTab = malloc(sizeof(int)*tabLength);
            for(int i=0; i<tabLength/2; i++) newTab[i] = tab[i];
            newTab[count] = number;
            free(tab);
            tab = newTab;
        }
        count++;
    }

    //for(int i=0; i<N; i++) printf("%d ", tab[i]);

    printf("\r\n");
    printf("N=%d ", count);
    printf("min=%d ", min(tab, count));
    printf("max=%d ", max(tab, count));
    printf("moy=%lf\r\n", moyenne(tab, count));
}