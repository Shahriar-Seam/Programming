#include <stdio.h>

#define yes printf("YES\n")
#define no printf("NO\n")

int main()
{
    int t, tt, n, e, o;

    scanf("%d", &t);

    while (t--) {
        scanf("%d", &tt);

        tt *= 2;

        e = o = 0;

        while (tt--) {
            scanf("%d", &n);

            (n % 2 == 0) ? e++ : o++;
        }

        (e == o) ? yes : no;
    }

    return 0;
}