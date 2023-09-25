#include <stdio.h>
int main()
{
    int t, n, i;
    int arr[101], x;

    scanf("%d", &t);

    while (t--)
    {
        scanf("%d", &n);

        for (i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        if (arr[0] >= 2) {
            x = 1;
        }

        else {
            x = 2;
        }

        for (i = 1; i < n; i++) {
            x++;
            if (arr[i] == x)
                x++;
        }
        
        printf("%d\n", x);
    }

    return 0;
}