#include <stdio.h>

int main()
{
    int n, i, correct_position, current_num;

    scanf("%d", &n);

    int arr[n];

    for (i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }

    for (i = 0; i < n; i++) {
        current_num = arr[i];
        correct_position = i - 1;

        while (correct_position >= 0 && arr[correct_position] > current_num) {
            arr[correct_position + 1] = arr[correct_position];
            correct_position--;
        }

        arr[correct_position + 1] = current_num;
    }

    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}