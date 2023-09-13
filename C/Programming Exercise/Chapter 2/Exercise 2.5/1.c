#include <stdio.h>

int main()
{
    int a, b, c, d, largest, temp1, temp2, temp3, largest_2nd;

    printf("Enter 4 numbers: ");
    scanf("%d %d %d %d", &a, &b, &c, &d);

    if (a > b && a > c && a > d) {
        largest = a;
        temp1 = b;
        temp2 = c;
        temp3 = d;
    }
    else if (b > a && b > c && b > d) {
        largest = b;
        temp1 = a;
        temp2 = c;
        temp3 = d;
    }
    else if (c > a && c > b && c > d) {
        largest = c;
        temp1 = a;
        temp2 = b;
        temp3 = d;
    }
    else {
        largest = d;
        temp1 = a;
        temp2 = b;
        temp3 = c;
    }

    printf("The largest number is: %d\n", largest);

    if (temp1 > temp2) {
        if (temp1 > temp3) {
            printf("2nd largest number is: %d\n", temp1);
        }
        else {
            printf("2nd largest number is: %d\n", temp3);
        }
    }
    else if (temp2 > temp1) {
        if (temp2 > temp3) {
            printf("2nd largest number is: %d\n", temp2);
        }
        else {
            printf("2nd largest number is: %d\n", temp3);
        }
    }

    return 0;
}