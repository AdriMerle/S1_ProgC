#include <stdio.h>

int main(int argc, char** argv) {
    printf("Nb of args : %d\r\n", argc);
    for(int i=0; i<argc; i++) {
        printf("%d : %p", i, *argv[i]);
    }
    printf("\r\n");
    return 0;
}