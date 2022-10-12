// run with ./progname arg | eg : ./prog9 10

#include <stdio.h>
#include <string.h>

// From prog7
int TP_atoi(const char s[]) {
    size_t n = strlen(s);
    int res = 0;
    for(int i=0; i<n; i++) {
        res = res * 10 + (int)(s[i]-48);
    }
    return (int)res;
}

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("False entry");

    } else {
        int n = TP_atoi(argv[1]);
        int isPremier;

        for(int i=2; i<=n; i++) {
            isPremier = 0;

            for(int j=2; j<i; j++) {
                if(i%j==0) isPremier++;
            }

            if(isPremier==0) printf("%d ", i);
        }
        printf("\r\n");
    }
}