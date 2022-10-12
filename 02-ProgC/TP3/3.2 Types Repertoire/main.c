#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define REP_SIZE 3

typedef struct {char *nom; char numero[10];} Personne;

void display(Personne p) {
    printf("%s : %s", p.nom, p.numero);
    printf("\r\n");
}

int main() {
    Personne rep[REP_SIZE];

    char input[256];
    int n;
    
    for(int i=0; i<REP_SIZE; i++) {
        //READ NAME
        scanf("%s", &input);
        n = strlen(input);
        rep[i].nom = malloc(sizeof(int)*n);
        for(int j=0; j<n; j++) rep[i].nom[j] = input[j];

        //READ NUMBER
        scanf("%s", &rep[i].numero); //To read a single word
    }

    printf("\r\nREPERTOIRE\r\n");
    for(int i=0; i<REP_SIZE; i++) display(rep[i]);

    return 0;
}