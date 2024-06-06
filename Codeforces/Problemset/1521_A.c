#include <stdio.h>

#define yes printf("YES\n")
#define no printf("NO\n")

int main()
{
    unsigned long long int t, a, b;

    scanf("%llu", &t);

    while (t--) {
        scanf("%llu %llu", &a, &b);

        if (b == 1) {
            no;
        }
        else {
            yes;
            printf("%llu %llu %llu\n", a, a * b, a * (b + 1));
        }
    }

    return 0;
}