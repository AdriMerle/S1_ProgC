// fils à gauche de i : 2*i+1 | à droite 2*i+2
// mère de i floor((i-1)/2) (avec des ints, seulement /)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int allocated; /* current allcoation of array */
  int filled;    /* number of items present in the binheap */
  int *array;    /* array of values */
} BinaryHeap;

/* Init allocates the structure BinaryHeap and
 * also the membre array with the given size 
 * it also fill allocated (size) and intializes 
 * filled to 0 */
BinaryHeap * Init(int size);

/* InsertValue insert value into the binary heap
 * the array is reallocated if necessary (allocated changed 
 * with respect to the new size )
 * filled is incremented by 1 */
void InsertValue(BinaryHeap * heap, int value);

/* ExtractMax returns 0 if the binary heap is empty
 * otherwise it return 1 and fills *val with the maximum 
 * value present in the binary heap
 * filled is decremented by 1  and the max value is removed
 * from the binary heap */
int ExtractMax(BinaryHeap * heap, int * val);

/* Destroy frees the structure and the array */
void Destroy(BinaryHeap * heap);

/* Display a BinaryHeap */
void display(BinaryHeap * h);


int main(void) {
    char lecture[100];
    int val;
    BinaryHeap * heap;
    heap = Init(10);

    fscanf(stdin,"%99s",lecture);
    while (strcmp(lecture,"bye")!=0) {
        if (strcmp(lecture,"insert")==0) {
            fscanf(stdin,"%99s",lecture);
            val = strtol(lecture,NULL,10);
            InsertValue(heap,val);
            printf("Insert ok : %d\r\n", val);
        } else if (strcmp(lecture,"extract")==0) {
            if(ExtractMax(heap,&val)) {
                printf("%d\r\n",val);
            }
            printf("Extract ok\r\n");
        }
        display(heap);
        fscanf(stdin,"%99s",lecture);
    }
    Destroy(heap);
    return 0;
}

BinaryHeap * Init(int size) {
    BinaryHeap* h = (BinaryHeap *)malloc(sizeof(BinaryHeap));
    h -> allocated = size;
    h -> filled = 0;
    h -> array = (int*)malloc(sizeof(int)*size);
    return h;
}

void InsertValue(BinaryHeap * heap, int value) {
    int *t = heap->array;

    if(heap->filled == heap->allocated) {
        (heap->allocated)++;
        t = (int*)realloc(t, sizeof(int)*heap->allocated);
    }
    t[heap->filled]=value; // Put the value to insert on the last cell

    int i = heap->filled, a; //Increase the value of filled and start from there
    heap->filled++;
    
    while(i>0) {
        if (t[(i-1)/2]<value) {
            a = t[(i-1)/2];
            t[(i-1)/2] = value;
            t[i] = a;
            i = (i-1)/2;
        } else  i=0;
    }

}

int ExtractMax(BinaryHeap * heap, int *res) {
    int i=0;
    int *t = heap->array;

    if(heap->filled=0) {
        return 0;
    } else {
        *res = t[0]; //max is on top

        while(i<=heap->filled) { //iterate to apply changes to the tree
            if(t[2*i+1]>=t[2*i+2]) {
                t[i] = t[2*i+1];
                i = 2*i+1;
            } else {
                t[i] = t[2*i+2];
                i = 2*i+2;
            }
        }
        /* il manque le cas de la derniere ligne :
            5
        4      2

        ici 4 va aller à la place de 5, et 2 à la place de 4 (2 swaps à faire)
        */
        return 1;
    }
    
}

void Destroy(BinaryHeap * heap) {
    free(heap->array);
    free(heap);
}

void display(BinaryHeap * h) {
    for(int i=0; i<h->filled; i++)  printf("%d ", h->array[i]);
    printf("\r\n");
}