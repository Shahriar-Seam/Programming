#include <stdio.h>

void permutations(int arr[], int n, int index)
{
    if (index == n) {
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }

        printf("\n");
        return;
    }

    arr[index] = 0;
    permutations(arr, n, index + 1);

    arr[index] = 1;
    permutations(arr, n, index + 1);
}

int main()
{
    int n;

    printf("Enter size: ");
    scanf("%d", &n);

    int arr[n];

    permutations(arr, n, 0);

    return 0;
}

// https://chat.openai.com/share/c8877d04-f7d4-4b7b-a274-54fbd81f25bc