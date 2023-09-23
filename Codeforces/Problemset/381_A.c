#include <stdio.h>

int main()
{
    int n, i, s = 0, d = 0, l_index, h_index;

    scanf("%d", &n);

    int arr[n];
    l_index = 0;
    h_index = n - 1;

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < n; i++) {
        if (i % 2 == 0) {
            if (arr[l_index] > arr[h_index]) {
                s += arr[l_index];
                l_index++;
            }
            else {
                s += arr[h_index];
                h_index--;
            }
        }
        else {
            if (arr[l_index] > arr[h_index]) {
                d += arr[l_index];
                l_index++;
            }
            else {
                d += arr[h_index];
                h_index--;
            }
        }
    }

    printf("%d %d", s, d);

    return 0;
}