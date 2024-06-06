#include <stdio.h>

int main()
{
    int t, T;
    int i, flag;

    scanf("%d", &t);

    while (t--) {
        scanf("%d", &T);

        int arr[T];
        flag = 1;

        for (i = 0; i < T; i++) {
            scanf("%d", &arr[i]);
        }

        if (T > 1) {
            for (i = 0; i < T - 1; i++) {
                if (arr[i + 1] - arr[i] > 1) {
                flag = 0 ;
                break;
                }
            }
        }

        (flag == 1) ? printf("YES\n") : printf("NO\n");
    }

    return 0;
}