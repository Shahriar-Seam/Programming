#include <stdio.h>

#define yes printf("YES\n")
#define no printf("NO\n")

int main()
{
    int t, n, f;

    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        f = 0;

        if ((n % 2020 == 0) || (n % 2021 == 0)) {
            yes;
            continue;
        }
        
        while (n >= 2020) {
            n -= 2020;

            if (n % 2021 == 0) {
                f = 1;
                break;
            }
        }

        f ? yes : no;
    }

    return 0;
}