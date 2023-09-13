#include <stdio.h>

int main()
{
    int arr[10];
    int i, count, j, max_count = 0, max_value;

    for (i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < 10; i++) {
        count = 0;

        for (j = 0; j < 10; j++) {
            if (arr[j] == arr[i]) {
                count++;
            }
        }

        if (count > max_count) {
            max_count = count;
            max_value = arr[i];
        }
    }

    printf("Most value: %d\n", max_value);

    return 0;
}