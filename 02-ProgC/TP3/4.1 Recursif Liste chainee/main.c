#include <stdio.h>
#include <stdlib.h>

typedef struct _elem {
    int val;
    struct _elem *next;
} elem;
elem* list = NULL;

void afficher(void) {
    elem *current = list;

    printf("\r\nContenu de la liste : ");

    while(current!=NULL) {
        printf("%d ", current -> val);
        current = current -> next;
    }
    printf("\r\n");
}

void ajouter_en_tete() {
    elem *e = malloc(sizeof(elem));
    scanf("%d", &(e -> val));
    e -> next = list;
    list = e;
}

void rechercher() {
    
}

int main(void) {
    while(1) {
        printf("menu:\n");
        printf("\t1: ajouter en tete\n");
        printf("\t2: afficher la liste\n");
        printf("\t0: quitter\n");

        int choix;
        scanf("%d", &choix);
        switch(choix) {
            case 0:
                goto fin;
            case 1:
                ajouter_en_tete();
                break;
            case 2:
                afficher();
                break;
            default:
                printf("choix incorrect\n");
                continue; // revenir au menu
        }
    }
fin:
    printf("au revoir\n");
    return 0;
}