#include <stdio.h>
#include <stdint.h>

int32_t main()
{
    int t;

    scanf("%d", &t);

    while (t--) {
        int h, m;

        scanf("%d %d", &h, &m);
        
        printf("%d\n", 24 * 60 - h * 60 - m);
    }

    return 0;
}