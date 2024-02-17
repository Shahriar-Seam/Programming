#include <stdio.h>

#define read(n) scanf("%d", &(n))
#define yes puts("YES")
#define no puts("NO")

int main()
{
    int t, n, m;

    read(t);

    while (t--) {
        read(n);
        read(m);

        if (n == 1 || m == 1 || (n == 2 && m == 2)) {
            yes;
        }
        else {
            no;
        }
    }

    return 0;
}