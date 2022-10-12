#include <stdio.h>
#include <assert.h>

double doublediv(double a, double b) {
    if(b==0)    return 0;
    else        return a/b;
}

double doublediv_2(double a, double b) {
    assert(b!=0);
    return a/b;
}

int main() {
    double a = 1, b = 0;
    printf("%lf \r\n", doublediv(a,b));
    printf("%lf \r\n", doublediv_2(a,b));
    return 0;
}