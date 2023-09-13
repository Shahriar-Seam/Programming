#include <stdio.h>

int main()
{
    int ara1[] = {3, 1, 5, 2, 4};
    int ara2[5];
    int i, minimum, index_2, minimum_index;

    for (index_2 = 0; index_2 < 5; index_2++) {
        minimum = 100000;

        for (i =0; i < 5; i++) {
            if (ara1[i] < minimum) {
                minimum = ara1[i];
                minimum_index = i;
            }
        }

        ara1[minimum_index] = 100000;
        ara2[index_2] = minimum;
    }

    for (index_2 = 0; index_2 < 5; index_2++) {
        printf("%d\n", ara2[index_2]);
    }

    return 1;
}