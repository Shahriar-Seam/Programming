#include <stdio.h>

int main()
{
    int t, i, c1, c2, c3, min, one, two, three;
    int arr[5001] = {0};

    scanf("%d", &t);

    c1 = c2 = c3 = 0;
    one = two = three = 0;

    for (i = 0; i < t; i++) {
        scanf("%d", &arr[i]);

        if (arr[i] == 1) c1++;
        else if (arr[i] == 2) c2++;
        else if (arr[i] == 3) c3++;
    }

    if (c1 <= c2 && c1 <= c3) {
        min = c1;
    }
    else if (c2 <= c1 && c2 <= c3) {
        min = c2;
    }
    else if (c3 <= c1 && c3 <= c2) {
        min = c3;
    }

    if (min == 0) {
        printf("0");
        return 0;
    }

    printf("%d\n", min);

    while (min--) {
        for (i = 0; i < t; i++) {
            if (one && two && three) {
                one = two = three = 0;
                break;
            }
            else if (!one && arr[i] == 1) {
                printf("%d ", i + 1);
                arr[i] = 0;
                one = 1;
            }
            else if (!two && arr[i] == 2) {
                printf("%d ", i + 1);
                arr[i] = 0;
                two = 1;
            }
            else if (!three && arr[i] == 3) {
                printf("%d ", i + 1);
                arr[i] = 0;
                three = 1;
            }
        }

        printf("\n");
    }

    return 0;
}