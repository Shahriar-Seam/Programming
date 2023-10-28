#include <stdio.h>

#define yes printf("YES\n")
#define no printf("NO\n")

int main()
{
    int t, tt, n, o, e;

    scanf("%d", &t);

    while (t--) {
        scanf ("%d", &tt);

        o = e = 0;

        while (tt--) {
            scanf ("%d", &n);

            if (n % 2 == 0) {
                e += n;
            }
            else {
                o += n;
            }
        }

        ((o % 2) == (e % 2)) ? yes : no;
    }

    return 0;
}