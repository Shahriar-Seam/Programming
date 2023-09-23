#include <stdio.h>

#define yes printf("YES\n")
#define no printf("NO\n")

int main()
{
    int t;
    int a, b, c, d;

    scanf("%d", &t);

    while (t--) {
        scanf("%d %d %d %d", &a, &b, &c, &d);

        if (a < b) {
            int temp = a;
            a = b;
            b = temp;
        }
        if (c < d) {
            int temp = c;
            c = d;
            d = temp;
        }

        if ((a > d) && (c > b)) yes;
        else no;
    }

    return 0;
}