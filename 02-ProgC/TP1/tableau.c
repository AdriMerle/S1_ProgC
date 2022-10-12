#include <stdio.h>
#include <string.h>

int main() {
    int average;

    int grades[3];

    grades[0] = 80;
    grades[1] = 85;
    grades[2] = 90;
    average = (grades[0] + grades[1] + grades[2]) / 3;
    printf("The average of the 3 grades is: %d\r\n", average);

    char name[11] = "John Smith";
    printf("Name: %s, Length: %d\r\n",name, strlen(name));
    return 0;
}