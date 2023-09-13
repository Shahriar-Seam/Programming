#include <stdio.h>
#include <math.h>

int main()
{
    int t, found;
    unsigned long long int n;

    scanf("%d", &t);

    while (t--) {
        scanf("%llu", &n);

        found = 0;

        if (n % 2 == 1) found = 1;
        else {
            while (n > 2) {
                if (n % 2 == 1) {
                    found = 1;
                    break;
                }

                n = n / 2;
            }
        }

        (found == 1) ? printf("YES\n") : printf("NO\n");
    }

    return 0;
}