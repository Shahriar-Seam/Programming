#include <stdio.h>

int main()
{
    int t;

    scanf("%d", &t);

    int arr1[t], arr2[t];

    for (int i = 0; i < t; i++) {
        scanf("%d %d", &arr1[i], arr2[i]);
    }

    return 0;
}