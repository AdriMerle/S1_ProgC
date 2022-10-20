#include <stdio.h>
#include <stdlib.h>

void remplir_(FILE * stream);
void remplacer(FILE *stream, const char k, int offset);
void lire(FILE *source, FILE *destination);
void lire_buffer(FILE *file);
void afficher_buffer();

int nb_lignes = 20, nb_col = 40;
char *buffer = NULL;

int main(int argc, char const *argv[]) {
    FILE *file = fopen("test.txt", "w+");
    remplir_(file);
    char k;
    int offset;

    lire_buffer(file);
    
    while(1) {
        afficher_buffer();

        //get char and replace stuff in file
        scanf(" %c", &k);
        if(k=='q') break;
        scanf(" %d", &offset); // equivalent to scanf("%d", &offset);
        
        if(offset > 0 && offset < (nb_lignes*nb_col) && offset%nb_col!=0)
            remplacer(file, k, offset);
        else printf("Wrong entry. Please try again \r\n");
    }
    fclose(file);
    return 0;
}

void remplacer(FILE *stream, const char k, int offset) {
    fseek(stream, offset, SEEK_SET);
    fputc(k, stream);
    rewind(stream);
}

void remplir_(FILE *stream) {
    for(int i=0; i<nb_lignes; i++) {
        for(int j=0; j<nb_col; j++) {
            fputc('_', stream);
        }
        fputc('\n', stream);
    }

    rewind(stream); //repositionne le curseur au début du fichier
}

void lire(FILE *source, FILE *destination) {
    char nextChar = fgetc(source);
    while(nextChar!=EOF) {
        fputc(nextChar, destination);
        nextChar = fgetc(source);
    }
}

void lire_buffer(FILE *source) {
    char nextChar = fgetc(source);
    int size=2, i=0;
    buffer = malloc(size*sizeof(char));
    while(nextChar!=EOF) {
        if(i<size) buffer[i] = fgetc(source);
        else {
            size *= 2;
            realloc(buffer, size);
            buffer[i] = fgetc(source);
        }
        i++;
        nextChar = fgetc(source);
    }
    buffer[i]=EOF;
}

void afficher_buffer() {
    int i = 0;
    while(buffer[i]!=EOF) {
        printf("%c", buffer[i]);
        i++;
    }
}