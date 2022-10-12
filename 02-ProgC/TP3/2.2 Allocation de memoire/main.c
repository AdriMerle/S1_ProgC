#include <stdio.h>
#include <stdlib.h>
#include "biblio.h"

int main() {
    int *tab, N;

    scanf("%d", &N);

    tab = malloc(sizeof(int)*N);

    for(int i=0; i<N; i++) scanf("%d", &tab[i]);

    //for(int i=0; i<N; i++) printf("%d ", tab[i]);

    printf("\r\n");
    printf("N=%d ", N);
    printf("min=%d ", min(tab, N));
    printf("max=%d ", max(tab, N));
    printf("moy=%lf\r\n", moyenne(tab, N));
}