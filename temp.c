#include <stdio.h>

int main()
{
    int x1, x2, x3, y1, y2, y3;
    
    printf("Enter coordinates of the 1st point (x1, y1): ");
    scanf("%d %d", &x1, &y1);
    printf("Enter coordinates of the 2nd point (x2, y2): ");
    scanf("%d %d", &x2, &y2);
    printf("Enter coordinates of the 3rd point (x3, y3): ");
    scanf("%d %d", &x3, &y3);

    if (((y1 - y2) * (x2 - x3) == (y2 - y3) * (x1 - x2)) && ((y1 - y3) * (x2 - x3) == (y2 - y3) * (x1 - x3))) {
        printf("All three points fall on a straight line\n");
    }
    else {
        printf("All three points don't fall on a straight line\n");
    }


    return 0;
}