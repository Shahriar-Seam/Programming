#include <stdio.h>
#include <math.h>

int arr[100005] = {0};
int count_arr[4] = {0};

void fill_array()
{
    int i = 0;

    while (1) {
        if (arr[i] == 0) break;
        else {
            if (arr[i] == 1) {
                count_arr[0]++;
            }
            else if (arr[i] == 2) {
                count_arr[1]++;
            }
            else if (arr[i] == 3) {
                count_arr[2]++;
            }
            else if (arr[i] == 4) {
                count_arr[3]++;
            }
        }

        i++;
    }
}

int count_num()
{
    int count = 0;

    count += count_arr[3];

    if (count_arr[2] >= count_arr[0]) {
        count += count_arr[2];
        count_arr[0] = 0;
    }
    else {
        count += count_arr[2];
        count_arr[0] = count_arr[0] - count_arr[2];
    }

    // printf("count1 = %d\n", count);

    // printf("%d %d %d %d\n", count_arr[0], count_arr[1], count_arr[2], count_arr[3]);

    if (count_arr[0] < count_arr[1] * 2) {
        count += count_arr[0] / 2;
        count_arr[1] -= count_arr[0] / 2;
        count_arr[0] = 0;
    }
    else {
        count += count_arr[1];
        count_arr[0] -= count_arr[1] * 2;
        count_arr[1] = 0;
    }

    // printf("count2 = %d\n", count);

    if (count_arr[1] > 1) {
        if (count_arr[1] % 2 == 0) {
            count += count_arr[1] / 2;
        }
        else {
            count += count_arr[1] / 2 + 1;
        }
    }
    else {
        count += count_arr[1];
    }

    // printf("count3 = %d\n", count);

    if (count_arr[0] > 0) {
        count += (count_arr[0] + 3) / 4;
    }

    // printf("count4 = %d\n", count);

    return count;
}

int main()
{
    int i, t, count;

    scanf("%d", &t);

    for (i = 0; i < t; i++) {
        scanf("%d", &arr[i]);
    }

    fill_array();
    count_num();

    count = ceil(count_arr[0] / 4.0) + ceil(count_arr[1] / 2.0) + count_arr[2] + count_arr[3];

    printf("%d", count);

    return 0;
}