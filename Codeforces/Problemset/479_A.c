#include <stdio.h>

int find_max(int arr[])
{
    int max = arr[0];
    for (int i = 1; i < 5; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    return max;
}

void create_array(int a, int b, int c, int arr[])
{
    int r1, r2, r3, r4;

    arr[0] = a + (b * c);
    arr[1] = a * (b + c);
    arr[2] = a * b * c;
    arr[3] = (a + b) * c;
    arr[4] = a + b + c;
}

int main()
{
    int a, b, c, max;
    int arr[5];
    
    scanf ("%d %d %d", &a, &b, &c);

    create_array(a, b, c, arr);
    max = find_max(arr);

    printf("%d", max);

    return 0;
}
