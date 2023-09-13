#include <stdio.h>

int main()
{
    int n;
    int i, even = 0, odd = 0, index;

    scanf("%d", &n);

    int arr[n];

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    if (((arr[0] % 2 == 0) && (arr[1] % 2 == 0)) || ((arr[1] % 2 == 0) && (arr[2] % 2 == 0)) || ((arr[2] % 2 == 0) && (arr[0] % 2 == 0))) {
        even = 1;
    }
    else {
        odd = 1;
    }

    if (even) {
        for (i = 0; i < n; i++) {
            if (arr[i] % 2 != 0) {
                index = i + 1;
                break;
            }
        }
    }
    if (odd) {
        for (i = 0; i < n; i++) {
            if (arr[i] % 2 == 0) {
                index = i + 1;
                break;
            }
        }
    }

    printf("%d", index);

    return 0;
}