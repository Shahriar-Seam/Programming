#include <stdio.h>

#define yes printf("YES\n")
#define no printf("NO\n")

int main()
{
    int t, w, h, n, count;

    scanf("%d", &t);

    while (t--) {
        scanf("%d %d %d", &w, &h, &n);

        count = 1;

        while (w % 2 == 0) {
            w /= 2;
            count *= 2;
        }

        
        while (h % 2 == 0) {
            h /= 2;
            count *= 2;
        }

        count >= n ? yes : no;
    }

    return 0;
}