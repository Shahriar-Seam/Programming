#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int words;
    int quality;
} array;

int main()
{
    int t, n, i, max, max_i;
    array *arr;

    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        arr = (array *) calloc(n, sizeof(array));

        for (i = 0; i < n; i++) {
            scanf("%d %d", &arr[i].words, &arr[i].quality);
        }

        max = -1;

        for (i = 0; i < n; i++) {
            if ((arr[i].words <= 10) && (arr[i].quality > max)) {
                max = arr[i].quality;
                max_i = i + 1;
            }
        }

        printf("%d\n", max_i);

        free(arr);
    }

    return 0;
}