#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void recurse(char t[], int i, int pos, int n, int *arr, int *index)
{
    if (i == n) {
        arr[*index] = pos;

        *index = *index + 1;

        return;
    }

    if (t[i] == '?') {
        recurse(t, i + 1, pos + 1, n, arr, index);
        recurse(t, i + 1, pos - 1, n, arr, index);
    }
    else if (t[i] == '+') {
        recurse(t, i + 1, pos + 1, n, arr, index);
    }
    else {
        recurse(t, i + 1, pos - 1, n, arr, index);
    }
}

int main()
{
    char s[15], t[15];
    int n, index = 0, i;
    int probable_positions = 0;
    int correct_position = 0, can_reach_correct_position = 0;

    gets(s);
    gets(t);

    n = strlen(s);


    int *arr = (int *) malloc(sizeof(int) * ((1 << n) + 1));
    int counter[25] = {};


    recurse(t, 0, 0, n, arr, &index);

    for (i = 0; i < n; i++) {
        correct_position += (s[i] == '+') ? 1 : -1;
    }

    for (i = 0; i < index; i++) {
        counter[arr[i] + 10]++;
    }

    can_reach_correct_position = counter[correct_position + 10] > 0;

    for (i = 0; i < 25; i++) {
        probable_positions += counter[i];
    }

    printf("%0.15f\n", can_reach_correct_position ? (1.0 * counter[correct_position + 10]) / probable_positions : 0);

    return 0;
}