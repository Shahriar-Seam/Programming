#include <stdio.h>

#define yes printf("YES\n")
#define no printf("NO\n")

int main()
{
    int t, a, b, c;

    scanf("%d", &t);

    while (t--) {
        scanf("%d %d %d", &a, &b, &c);

        if ((a + b >= 10) || (a + c >= 10) || (c + b >= 10)) yes;
        else no;
    }

    return 0;
}