// Write a recursive solution to compute lcm of 
// two integers

#include <stdio.h>

int LCM(int a, int b, int lcm)
{
    if (lcm % a == 0 && lcm % b == 0) {
        return lcm;
    }
    else {
        LCM(a, b, lcm + 1);
    }
}

int main()
{
    int a, b, lcm;

    scanf("%d %d", &a, &b);

    lcm = a > b ? a : b;

    printf("%d\n", LCM(a, b, lcm));

    return 0;
}