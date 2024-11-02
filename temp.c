#include <stdio.h>
#include <math.h>

int main()
{
    int a, b, c;
    // printf("Enter the 3 Number:");
    scanf("%d %d %d", &a, &b, &c);
    
    int i = pow(a, 2), j = pow(b, 2), k = pow(c, 2);
    
    if (i == j + k)
        printf("The 3 Number can make a Right angled triangle");
    else if (j == k + i)
        printf("The 3 Number can make a Right angled triangle");
    else if (k == j + i)
        printf("The 3 Number can make a Right angled triangle");
    else
        printf("The 3 Number can not make a Right angled triangle");
    
    return 0;
}