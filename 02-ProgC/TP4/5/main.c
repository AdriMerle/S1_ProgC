#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/*
fgets stops to read if
1. it finds a EOF
2. it finds a \n
3. you already read size-1 characters
*/

int get_nb_lines(FILE * stream);


int main() {
    srandom(time(NULL));

    FILE *out = fopen("discours.txt", "w+");
    FILE *stream;

    char * string;
    int nb_lines, count;
    long rand;

    char res[100], chr;

    for(int i=1; i<=4; i++) {
        if      (i==1)  string = "colonne1.txt";
        else if (i==2)  string = "colonne2.txt";
        else if (i==3)  string = "colonne3.txt";
        else            string = "colonne4.txt";
        
        // Get number of lines
        stream = fopen(string, "r");
        nb_lines = get_nb_lines(stream);
        fclose(stream);

        // Get a random line
        rand = random()%nb_lines;
        count = 0;
        stream = fopen(string, "r");
        chr = getc(stream);

        while(count != rand) {
            if (chr == '\n') count++;
            chr = getc(stream);
        }
        fseek(stream, -1, SEEK_CUR); // Backwards of 1 char
        
        // Get the line wanted and output it to file
        fgets(res, 100, stream);
        fputs(res, out);
        fclose(stream);
    }
    fclose(out);
    return 0;
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