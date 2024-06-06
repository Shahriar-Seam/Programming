#include <stdio.h>
#include <math.h>

#define yes printf("YES\n")
#define no printf("NO\n")

int is_int(double n)
{
    return n == (long long int) n;
}

int main()
{
    long long int t, n, a;
    double b;

    scanf("%lld", &t);

    while (t--) {
        scanf("%lld", &n);

        for (a = 1; a <= 10000; a++) {
            b = cbrt((double) n - a * a * a);

            if (b <= 0) {
                no;
                break;
            }
            else if (is_int(b)) {
                yes;
                break;
            }
        }
    }

    return 0;
}