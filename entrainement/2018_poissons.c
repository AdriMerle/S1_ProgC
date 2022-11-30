#include <stdio.h>

#define MAX_NB_POISSONS 1000

int main() {
    int nr, nn, poids; //nr = nombre rouges, mr = moyenne rouges

    float mr=0, mn=0;

    scanf("%d", &nr); // NB rouges
    scanf("%d", &nn); // NB noirs

    int i=0;
    while(i<nr) {
        scanf("%d", &poids);
        mr += poids;
        i++;
    }
    mr /= nr;

    i=0;
    while(i<nr) {
        scanf("%d", &poids);
        mn += poids;
        i++;
    }
    mn /= nn;

    if      (mr>mn) printf("R\r\n");
    else if (mn>mr) printf("N\r\n");
    else            printf("RN\r\n");



    return 0;
}