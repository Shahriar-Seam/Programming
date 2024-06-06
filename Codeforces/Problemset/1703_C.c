#include <stdio.h>

int main()
{
    int t, n, c;
    int i;
    char ch;

    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        int arr[n];

        for (i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        for (i = 0; i < n; i++) {
            scanf("%d", &c);
            getchar();

            while (c--) {
                scanf("%c", &ch);

                if (ch == 'D') {
                    arr[i]++;
                }
                else if (ch == 'U') {
                    arr[i]--;
                }
            }
        }

        for (i = 0; i < n; i++) {
            if (arr[i] < 0) {
                arr[i] += 10;
            }
            if (arr[i] >= 10) {
                arr[i] = arr[i] % 10;
            }
            printf("%d ", arr[i]);
        }

        printf("\n");
    }

    return 0;
}