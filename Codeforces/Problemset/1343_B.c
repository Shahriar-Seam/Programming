#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define yes printf("YES\n")
#define no printf("NO\n")

int main()
{
    int t, n, i;
    int *arr_e, *arr_o;

    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        if (n % 4 != 0) {
            no;
            continue;
        }

        int n2 = n / 2;

        arr_e = (int *) malloc(sizeof(int) * n2);
        arr_o = (int *) malloc(sizeof(int) * n2);

        for (i = 0; i < n2; i++) {
            arr_e[i] = (i + 1) * 2;
        }
        for (i = 0; i < n2; i++) {
            arr_o[i] = (i + 1) * 2 - 1;
        }

        arr_o[--i] += n2;

        yes;
        for (i = 0; i < n2; i++) {
            printf("%d ", arr_e[i]);
        }
        for (i = 0; i < n2; i++) {
            printf("%d ", arr_o[i]);
        }
        printf("\n");

        free(arr_e);
        free(arr_o);
    }

    return 0;
}