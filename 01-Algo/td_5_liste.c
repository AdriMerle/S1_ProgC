#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

typedef struct _elem {
    int data;
    struct _elem * next;
} elem;

typedef struct {
    elem * start;
    elem * end;
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
        //display(file);
        fscanf(stdin,"%99s",lecture);
    }
    destroy(file);
    return 0;
}

File * Init() {
    File* f = (File *)malloc(sizeof(File));
    f->start = NULL;
    f->end = NULL;

    return f;
}

void destroy(File * f) {
}

void add_elem(File * f, int val) {
    if (f->end==NULL) {
        elem * new = (elem *)malloc(sizeof(elem));
        new->data = val;
        new->next = NULL;
        f->start = new;
        f->end = new;
    } else {
        elem * new = (elem *)malloc(sizeof(elem));
        new->data = val;
        new->next = NULL;
        (f->end)->next = new;
        f->end = (f->end)->next;
    }
}

void disp_next_elem(File * f) {
    if(f->start!=f->end) {
        printf("%d\r\n", (f->start)->data);
        elem * old = f->start;
        f->start = (f->start)->next;
        free(old);
    } else if (f->start != NULL) {
        printf("%d\r\n", (f->start)->data);
        f->start = NULL;
        f->end = NULL;
    }
}

void display(File * f) {
    elem *current = f->start;

    printf("\r\nFile : ");
    while(current!=NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\r\n");
}