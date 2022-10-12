#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    //Initialiser le module aléatoire
    srand((unsigned) time(NULL));

    // Saping de taille aléatoire
    int h=rand() % 20;
    int th=h*2/5;
    int tl=rand() % th;

    while(tl%2==0) tl=(rand() % th);

    int bh=(rand() % h) + 1;
    int bl=rand() % (2*(h-bh)-1) + 1;

    //Afficher feuillage
    int line, col;
    for(line=0; line<h; line++) {
        for(col=0; col<h-line-1; col++) printf(" ");
        for(col=0; col<2*line+1; col++) {
            if(((h-line)==bh) && ((col+1)==bl)) printf("O");
            else printf("*");
        }
        printf("\r\n");
    }

    for(line=0; line<th; line++) {
        for(col=0; col<h-tl/2-1; col++) printf(" ");
        for(col=0; col<tl; col++) printf("|");
        printf("\r\n");
    }
}