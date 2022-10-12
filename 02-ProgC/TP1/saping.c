#include <stdio.h>

int main() {
    int h=6;
    int th=2;
    int tl=3;

    int bh=2;
    int bl=3;

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