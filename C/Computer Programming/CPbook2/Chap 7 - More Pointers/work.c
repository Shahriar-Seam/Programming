#include <stdio.h>
#include <stdlib.h>

int compare_func(const void *a, const void *b)
{
    return ((* (int *) a) - (* (int *) b));
}

int main()
{
    int n, i, key;
    int *arr, *item;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    arr = (int *) malloc(sizeof(int) * n);

    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the key: ");
    scanf("%d", &key);

    qsort(arr, n, sizeof(int), compare_func);
    item = (int *) bsearch(&key, arr, n, sizeof(int), compare_func);

    if (item == NULL) {
        printf("Key was not found in the array.\n");
    }
    else {
        printf("%d was found in the array.\n", *item);
    }

    return 0;
}