#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* raccourcis vers les types clé et valeur */
typedef char * Key;
typedef char * Value;

/* état d’une case (peut être fait aussi avec un enum) */
#define EMPTY 0
#define SET 1
#define REMOVED 2

/* utile pour l’affichage */
const char * Labels[] = {"Empty","Set","Removed"};

/* une cellule de la table */
typedef struct {
    Key key;
    unsigned char status;
    Value val;
} Data;

/* la table de hachage elle-même */
typedef struct {
    Data * tab;
    int size;
} HashTable;

void error(void);
void search(void);
void research(HashTable * h, char * key, int * tab);
void display(HashTable * h);

int main(void) {
    int size;
    char lecture[100];
    char * key;
    char * val;
    int * result;
    HashTable * h;
    if (fscanf(stdin,"%99s",lecture)!=1)    error();
    while (strcmp(lecture,"bye")!=0) {
        /* Initialization */
        if (strcmp(lecture,"init")==0 || strcmp(lecture,"it")==0) {
            if (fscanf(stdin,"%99s",lecture)!=1)    error();
            size = atoi(lecture);
            h = malloc(sizeof(HashTable));
            h->tab = malloc(sizeof(Data)*size);
            h->size = size;
            display(h);
        }
        /* Inserting */
        else if (strcmp(lecture,"insert")==0 || strcmp(lecture,"is")==0) {
            if (fscanf(stdin,"%99s",lecture)!=1)    error();
            key = strdup(lecture);
            if (fscanf(stdin,"%99s",lecture)!=1)    error();
            val = strdup(lecture);
            /*result = research(h, key, val);
            if(result[0]==1) */
        /* Suppressing */
        } else if (strcmp(lecture,"delete")==0 || strcmp(lecture,"dl")==0) {
            if (fscanf(stdin,"%99s",lecture)!=1)    error();
            key = strdup(lecture);
            
        /* Research and display */
        } else if (strcmp(lecture,"query")==0 || strcmp(lecture,"qu")==0) {
            if (fscanf(stdin,"%99s",lecture)!=1)    error();

        /* Destruction */
        } else if (strcmp(lecture,"destroy")==0 || strcmp(lecture,"ds")==0) {
            free(h->tab);
            free(h);

        /* Statistics */
        } else if (strcmp(lecture,"stats")==0 || strcmp(lecture,"st")==0) {

        }
        if (fscanf(stdin,"%99s",lecture)!=1)    error();
    }
    return 0;
}

/* fonction de décalage de bit circulaire */
unsigned int shift_rotate(unsigned int val, unsigned int n) {
    n = n%(sizeof(unsigned int)*8);
    return (val<<n) | (val>> (sizeof(unsigned int)*8-n));
}

/* fonction d'encodage d'une chaîne de caractères */
unsigned int Encode(Key key) {
    unsigned int i;
    unsigned int val = 0;
    unsigned int power = 0;
    for (i=0;i<strlen(key);i++) {
        val += shift_rotate(key[i],power*7);
        power++;
    }
    return val;
}

/* fonction de hachage simple qui prend le modulo */
unsigned int hash(unsigned int val, unsigned int size) {
    return val%size;
}

/* fonction de hachage complète à utiliser */
unsigned int HashFunction(Key key, unsigned int size) {
    return hash(Encode(key),size);
}

/* placer ici vos définitions (implémentations) de fonctions ou procédures */
void error(void) {
    printf("input error\r\n");
    exit(0);
}

void display(HashTable * h){
    int i = 0;
    if (h->tab==NULL) printf("Sorry HashTable is not initialised");
    else {
        while (i<h->size){
            if (h->tab[i].val!=NULL){
                printf("i = %d, valeur = %c \r\n",i,  *(h->tab[i].val));
            }
            i++;
            printf("hey2");
        }
    }
}
/*  1st value :
        0 -> X not found
        1 -> X found
    2nd value :
        Position where X is or where it should be (-1 if no space left for X)
 */
void research(HashTable * h, char * key, int * tab) { // X = (key, val)
    int i = HashFunction(key,h->size), count = 0;

    while(!(count==1 && i==*key)){ // while 
        if(h->tab[i].status==SET && h->tab[i].key==key) { // If X is found
            tab[0] = 1;
            tab[1] = i;
            goto end;
        } else if (h->tab[i].status==EMPTY) { // If the space is available
            tab[0] = 0;
            tab[1] = i;
            goto end;
        }   
        // Increment
        if (i==h->size-1) i=0;
        else i++;
    }
    // If not found and no space
    tab[0] = 0;
    tab[1] = -1;
    end:;
}