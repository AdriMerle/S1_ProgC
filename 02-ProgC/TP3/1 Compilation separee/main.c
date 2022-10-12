#include <stdio.h>
#include "biblio.h"

#define MAXLENGTH 100

int main() {
    int count=0, tab[MAXLENGTH], tablength;

    scanf("%d", &tablength);

    while(count<tablength) {
        scanf("%d", &tab[count]);
        count++;
    }

    // for(int i=0; i<tablength; i++) {
    //     printf("%d ", tab[i]);
    // }

    //printf("\r\n");

    printf("SOMME   = %d\r\n", somme(tab));
    printf("PRODUIT = %d\r\n", produit(tab));
    printf("MOYENNE = %lf\r\n", moyenne(tab));
    
    return 0;
}