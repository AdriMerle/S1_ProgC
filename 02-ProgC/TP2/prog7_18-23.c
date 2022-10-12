// COMPILE WITH gcc -o prog7 prog7_18-.c -lm

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int TP_strccmp(const char s1[], const char s2[]) {
    size_t n = strlen(s1);
    for(int i=0; i<n; i++) {
        if      (s1[i] < s2[i]) return -1;
        else if (s1[i] > s2[i]) return  1;
    }
    return 0;
}

int TP_atoi(const char s[]) {
    size_t n = strlen(s);
    int res = 0;
    for(int i=0; i<n; i++) {
        res = res * 10 + (int)(s[i]-48);
    }
    return (int)res;
}

void TP_atoa(int nb) {
    int n = floor(log10(abs(nb))) + 1;

    for(int i=n-1; i>=0; i--) {
        printf("%d", nb/((int)(pow(10,i))));
        nb = nb%((int)(pow(10,i)));
    }
    printf("\r\n");
}

int main() {
    char s1[] = "aba";
    char s2[] = "abc";
    //printf("C=%d | TP=%d\r\n", strcmp(s1,s2), TP_strccmp(s1, s2));

    char s3[] = "23656";
    //printf("C=%d | TP=%d\r\n", atoi(s3), TP_atoi(s3));

    TP_atoa(563);

    return 0;
}