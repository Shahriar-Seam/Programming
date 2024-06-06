#include <stdio.h>

#define yes printf("YES\n")
#define no printf("NO\n")
#define xyz printf("%d %d %d\n", x, y, z)

int main()
{
    int t, n, x, y, z;

    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        if (n < 7) {
            no;
            continue;;
        }

        else if (n == 9) {
            no;
            continue;
        }

        else if ((n % 3 == 1) || (n % 3 == 2)) {
            x = 1;
            y = 2;
            z = n - 3;

            yes;
            xyz;

            continue;
        }

        else {
            x = 1;
            y = 4;
            z = n - 5;

            yes;
            xyz;

            continue;
        }
    }

    return 0;
}