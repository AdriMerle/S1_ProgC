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

void supprimer() {
    elem *e = list;
    elem *nextElem;
    int val;
    scanf("%d", &val);

    while(e->next != NULL) {
        nextElem = e->next;
        if(nextElem->val == val) {
            printf("%d ", nextElem->val);
            e->next = nextElem->next;
            free(nextElem);
        }
        e = e->next;
    }
}

void dupliquer() {
    elem *e = list, *new;
    int input;

    scanf("%d", &input);

    while(e->next != NULL) {
        if(e->val == input) {
            new = malloc(sizeof(elem));
            new->next = e->next;
            new->val = input;
            e->next = new;
            e = new->next;
        } else {
            e = e->next;
        }
        
    }
    afficher();
}

int est_triee() {
    int trie = 1;   // Si la liste est triée, trie=1
    elem *e = list;
    while(e->next != NULL) {
        if(e->next->val < e->val) trie=0;
        e = e->next;
    }

    if(trie==0) printf("non\r\n");
    else        printf("oui\r\n");
    
    return trie;
}

void ajouter_en_place() {
    printf("La liste est-elle triée : ");
    if (est_triee()==1) {
        elem *e = list;
        int input;
        scanf("%d", &input);

        while(e->next!=NULL && e->next->val<input)  e = e->next;

        elem *new = malloc(sizeof(elem));
        new->next=e->next;
        new->val = input;
        e->next = new;
    } else printf("On ne peut donc pas insérer.\r\n");
    printf("\r\n");
}


int main(void) {
    while(1) {
        printf("menu:\n");
        printf("\t0: quitter\n");
        printf("\t1: ajouter en tete\n");
        printf("\t2: afficher la liste\n");
        printf("\t3: rechercher\n");
        printf("\t4: ajouter en queue\n");
        printf("\t5: supprimer\n");
        printf("\t6: dupliquer\n");
        printf("\t7: la liste est-elle triée ?\n");
        printf("\t8: ajouter en place\n");

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
            case 5:
                supprimer();
                break;
            case 6:
                dupliquer();
                break;
            case 7:
                est_triee();
                break;
            case 8:
                ajouter_en_place();
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