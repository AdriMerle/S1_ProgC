#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

// fils à gauche de i : 2*i+1 | à droite 2*i+2
// mère de i floor((i-1)/2) (avec des ints, seulement /)

typedef struct {
  int iStart;       /* indice of the first item in the file */
  int iEnd;         /* indice of the last item in the file */
  int *array;       /* array of values */
} File;

/* Init allocates the structure File and
 * also the membre array with the given size 
 * it also fill allocated (size) and intializes 
 * filled to 0 */
File * Init();

/* Destroy frees the structure and the array */
void destroy(File * f);

/* Display a file */
void display(File * f);

void add_elem(File * f, int val);
void disp_next_elem(File *f);

int main(void) {
    char lecture[100];
    int val;
    File * file;
    file = Init(10);

    fscanf(stdin,"%99s",lecture);
    while (strcmp(lecture,"bye")!=0 && strcmp(lecture,"b")!=0) {
        // ADD ELEM
        if (strcmp(lecture,"queue")==0 || strcmp(lecture,"q")==0) {
            fscanf(stdin,"%99s",lecture);
            val = strtol(lecture,NULL,10);
            add_elem(file, val);

        // PRINT ELEM AND ERASE FROM FILE
        } else if (strcmp(lecture,"dequeue")==0 || strcmp(lecture,"d")==0) {
            disp_next_elem(file);
        }
        fscanf(stdin,"%99s",lecture);
    }
    destroy(file);
    return 0;
}

File * Init() {
    File* f = (File *)malloc(sizeof(File));
    f->iStart = 0;
    f->iEnd = 0;
    f->array = (int*)malloc(sizeof(int)*SIZE);
    return f;
}

void destroy(File * f) {
    free(f->array);
    free(f);
}

void add_elem(File * f, int val) {
    if (f->iStart-1!=f->iEnd) {     //otherwise file is full
        if (f->iEnd<SIZE-1) {
            f->array[f->iEnd] = val;
            (f->iEnd)++;
        } else if (f->iEnd==SIZE-1) {
            f->array[f->iEnd] = val;
            f->iEnd = 0;
        }
    }
}

void disp_next_elem(File * f) {
    if(f->iStart-1!=f->iEnd && f->iStart!=f->iEnd) {
        printf("%d\r\n", f->array[f->iStart]);
        if (f->iStart<SIZE-1) {
            (f->iStart)++;
        } else if (f->iEnd==SIZE-1) {
            f->iStart = 0;
        }
    }
}