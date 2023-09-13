#include <stdio.h>

int GCD(int num1, int num2)
{
    while (num2 != 0) {
        int temp = num2;
        num2 = num1 % num2;
        num1 = temp;
    }
    return num1;
}

int main()
{
    int t;
    int n1, n2;
    int a, b, found;

    scanf("%d", &t);

    while (t--) {
        scanf("%d%d", &n1, &n2);

        a = b = (n1 + n2) / 2;
        found = 0;

        while (1) {
            for ( ; a > 0; a--) {
                if ((GCD(a, b) != 1) && ((n1 <= (a + b)) && (a + b) <= n2)) {
                    found = 1;

                    break;
                }
            }

            b++;

            if (found) break;
        }

        if (found) {
            printf("%d %d\n", a, b);
        }
        else {
            printf("-1\n");
        }
        
    }

    return 0;
}