#include <stdio.h>

void fill_array(int arr[])
{
    int i, j;

    for (i = 1, j = 0; i <= 1666; i++) {
        if (!((i % 3 == 0) || (i % 10 == 3))) {
            arr[j] = i;
            j++;
        }
    }
}

int main()
{
    int t, k;
    int arr[1001];

    fill_array(arr);

    scanf("%d", &t);

    while (t--) {
        scanf("%d", &k);

        printf("%d\n", arr[k - 1]);
    }

    return 0;
}