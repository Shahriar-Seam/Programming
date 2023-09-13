#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[101] = {0};
    int i = 0, count = 0, mv1, mv2;

    while (scanf("%c", &arr[i]) && ((char) arr[i] != '\n')) {
        i++;
    }

    arr[i] = -1;

    for (i = 0; arr[i] >= 0; i++) {
        arr[i] = arr[i] - 97;
    }

    mv1 = abs(0 - arr[0]);
    mv2 = abs(26 - arr[0]);

    if (mv1 < mv2) {
        count += mv1;
    }
    else {
        count += mv2;
    }

    for (i = 1; arr[i] >= 0; i++) {
        mv1 = abs(arr[i - 1] - arr[i]);
        mv2 = 26 - abs(arr[i - 1] - arr[i]);

        if (mv1 < mv2) {
            count += mv1;
        }
        else {
            count += mv2;
        }
    }

    printf("%d", count);

    return 0;
}