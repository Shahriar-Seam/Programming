#include <stdio.h>

int main()
{
    int t;
    int a, b, c;

    scanf("%d", &t);

    while (t--) {
        scanf("%d%d%d", &a, &b, &c);

        int i = 0;

        if (a < b) {
            int temp = a;
            a = b;
            b = temp;
        }

        int m = (a + b) / 2.0;

        while (1) {
            if (a <= m) {
                break;
            }

            a = a - c;

            i++;
        }


        printf("%d\n", i);
    }

    return 0;
}