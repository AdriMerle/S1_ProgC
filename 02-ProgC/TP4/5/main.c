#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
fgets stops to read if
1. it finds a EOF
2. it finds a \n
3. you already read size-1 characters
*/

int get_nb_lines(FILE * stream);
void print_random();

int main() {
    srandom(time(NULL));

    FILE *stream = fopen("colonne1.txt", "r");

    //iterate over the 4 files (not done yet)
    int nb_lines = get_nb_lines(stream);
    fclose(stream);

    stream = fopen("colonne1.txt", "r");
    long rand = random()%nb_lines;
    int count = 0;
    char chr = getc(stream);

    while(count != rand) {
        if (chr == '\n') count++;
        chr = getc(stream);
    }
    char res[100];
    fgets(res, 100, stream);
    printf(res);
    return 0;
}

void print_random_line() {

}

int get_nb_lines(FILE * stream) {
    char chr = getc(stream);
    int count=0;

    while (chr != EOF) {
        //Count whenever new line is encountered
        if (chr == '\n') count++;
        chr = getc(stream);
    }
    return count;
}