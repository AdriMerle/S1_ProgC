#include <stdio.h>
#include <errno.h>
#include <math.h>

int main() {
    errno = 0;
    double puissance = pow(2,4);
    printf("%lf | %d \r\n", puissance, errno);
    puissance = pow(-1,0.5);
    printf("%lf | %d \r\n", puissance, errno);
    return 0;
}