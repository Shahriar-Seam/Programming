#include <stdio.h>
#include <math.h>

#define yes printf("YES\n")
#define no printf("NO\n")

void check()
{
    int a, b;
    
    scanf("%d %d", &a, &b);

    if ((a % 2 == 1) && b == 1) {
        yes;
    }
    else if (((a % 2 == 0) && (b % 2 == 1)) || ((a % 2 == 1) && (b % 2 == 0))) {
        no;
    }
    else if (b <= sqrt(a)) {
        yes;
    }
    else {
        no;
    }
}

int main()
{
    int t;

    scanf("%d", &t);

    while (t--) {
        check();
    }

    return 0;
}