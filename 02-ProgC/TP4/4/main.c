#include <stdio.h>
#include <stdlib.h>

void remplir_(FILE * stream);
void remplacer(FILE *stream, const char k, int offset);

int nb_lignes = 20, nb_col = 40;

int main(int argc, char const *argv[]) {
    FILE *file = fopen("test.txt", "w+");
    remplir_(file);
    char k = 'a';
    int offset;
    char uselsess;

    while(k!='q') {
        char nextChar = fgetc(file);
        //Print file content
        while(nextChar!=EOF) {
            fputc(nextChar, stdout);
            nextChar = fgetc(file);
        }
        //get char and replace stuff in file
        scanf(" %c", &k);
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