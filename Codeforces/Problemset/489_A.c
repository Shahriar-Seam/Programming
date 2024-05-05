#include <stdio.h>
#include <stdlib.h>

int *indices;
int ind_size = 0;

void swap(int *a, int *b)
{
    *a ^= *b ^= *a ^= *b;
}

int compare(const void *a, const void *b)
{
    return * (int *) a - * (int *) b;
}

int is_present(int index)
{
    int i;

    for (i = 0; i < ind_size; i++) {
        if (indices[i] == index) {
            return 1;
        }
    }

    return 0;
}

int find(int *arr, int key, int n)
{
    int i;

    for (i = n - 1; i >= 0; i--) {
        if (arr[i] == key && (is_present(i) == 0)) {
            ind_size++;

            return i;
        }
    }

    return i;
}

int main()
{
    int n, i, j = 0, cnt = 0, k = 0;

    scanf("%d", &n);

    int *arr = (int *) malloc(sizeof(int) * n);
    int *arr2 = (int *) malloc(sizeof(int) * n);
    int **arr3 = (int **) malloc(sizeof(int *) * n);
    indices = (int *) malloc(sizeof(int) * n);

    for (i = 0; i < n; i++) {
        arr3[i] = (int *) malloc(sizeof(int) * 2);
    }

    for (i = 0; i < n; i++) {
        scanf("%d", arr + i);

        arr2[i] = arr[i];
    }

    qsort(arr, n, sizeof(int), compare);

    for (i = 0; i < n; i++) {
        j = find(arr2, arr[i], n);

        if (i != j) {
            swap(arr2 + i, arr2 + j);

            arr3[k][0] = i;
            arr3[k][1] = j;

            k++;
            cnt++;
        }
    }

    printf("%d\n", cnt);

    for (i = 0; i < k; i++) {
        printf("%d %d\n", arr3[i][0], arr3[i][1]);
    }

    return 0;
}