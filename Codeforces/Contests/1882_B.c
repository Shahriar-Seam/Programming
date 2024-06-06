#include <stdio.h>

int _count(int arr[])
{
    int i, c = 0;

    for (i = 0; i < 51; i++) {
        if (arr[i] != 0) {
            c++;
        }
    }

    return c;
}

int main()
{
    int n, t, i, a;

    scanf("%d", &n);

    while (n--) {
        scanf("%d", &t);

        int T = t;

        int arr[501] = {0};

        while (t--) {
            scanf("%d", &i);

            while (i--) {
                scanf("%d", &a);

                arr[a]++;
            }
        }

        if (T != 1) {
            printf("%d\n", _count(arr) - 1);
        }
        else {
            printf("0\n");
        }
    }

    return 0;
}