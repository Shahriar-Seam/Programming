#include <stdio.h>
#include <math.h>

#define yes printf("YES\n")
#define no printf("NO\n")

int main()
{
    int t, a, n1, n2;

    scanf("%d", &t);

    while (t--) {
        scanf("%d", &a);

        n1 = (int) floor((double) 360 / (180 - a));
        n2 = (int) ceil((double) 360 / (180 - a));

        (n1 == n2) ? yes : no;
    }

    return 0;
}