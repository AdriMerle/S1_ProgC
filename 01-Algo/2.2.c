#include <stdio.h>

int main() {
    int tmax;
    scanf("%d", &tmax);

    int a, i=0, j;
    int size_obj;
    int obj[100];

    a=scanf("%d", &a);
    while(a!=-1) {
        scanf("%d", &a);
        obj[i] = a;
        i++;
    }
    size_obj = i;
    

    int res[tmax];

    res[0] = 1;

    for(i=1; i<tmax; i++) {
        for(j=0; j<size_obj; j++) {
            if ((i-obj[j]) >= 0 && (res[i-obj[j]])) {
                res[i] = 1;
                break;
            } else {
                res[i] = 0;
            }
        }
    }

    for(i=0; i<tmax; i++) {
        printf("%d ", res[i]);
    }
    

    return 0;
}