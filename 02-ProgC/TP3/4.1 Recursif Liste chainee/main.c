#include <stdio.h>
#include <stdlib.h>

typedef struct _elem {
    int val;
    struct _elem *next;
} elem;

elem* list = NULL;

void afficher() {
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
    elem *e = list;
    int val, i=0, found=0;
    scanf("%d", &val);

    while(e->next!=NULL && e->val!=val) {
        i++;
        e = e->next;
        if(e->next==NULL) {
            found==1;
        }
    }
    if(found==0)     printf("Je n'ai pas trouvé %d\r\n", val);
    else                printf("Position de %d : %d\r\n", val, i);
}

void ajouter_en_queue() {
    elem *e = list, *new = malloc(sizeof(elem));
    int val;
    scanf("%d", &val);

    while(e->next != NULL) e = e->next;

    new->val = val;
    new->next = NULL;    
    e->next = new;
}

int main(void) {
    while(1) {
        printf("menu:\n");
        printf("\t1: ajouter en tete\n");
        printf("\t2: afficher la liste\n");
        printf("\t3: rechercher\n");
        printf("\t4: ajouter en queue\n");
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
            case 3:
                rechercher();
                break;
            case 4:
                ajouter_en_queue();
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