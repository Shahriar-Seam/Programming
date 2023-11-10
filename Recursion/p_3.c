/*
Write a recursive program to remove all odd integers 
from an array. You must not use any extra array 
or print anything in the function. Just read input, 
call the recursive function, 
then print the array in main().
*/

#include <stdio.h>

void recurse(int *arr, int i, int j, int *n)
{
    if (i == *n) {
        *n = j;
        return;
    }

    if (arr[i] % 2 == 0) {
        arr[j++] = arr[i];
    }

    recurse(arr, i + 1, j, n);
}

int main()
{
    int n, i, arr[100];
    
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    recurse(arr, 0, 0, &n);

    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}