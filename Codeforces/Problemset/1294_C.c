#include <stdio.h>
#include <math.h>

#define yes printf("YES\n")
#define no printf("NO\n")

int is_int(double a)
{
    return (a == (int) a);
}

int main()
{
    int t, n, a, b, c, r;

    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        r = sqrt(n);

        for (a = 2; a <= r; a++) {
            if (n % a == 0) {
                break;
            }
        }

        for (b = a + 1; b <= sqrt(n / a); b++) {
            if ((n / a) % b == 0) {
                break;
            }
        }

        c = n / (a * b);

        if (c > a && c != b && (a * b * c == n)) {
            yes;
            printf("%d %d %d\n", a, b, c);
        }
        else {
            no;
        }
    }

    return 0;
}