#include <stdio.h>

int main()
{
    int n, sum = 0, i, temp, f = 1;
    double avg;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &temp);

        sum += temp;

        if (temp == 3) {
            f = 0;
        }
    }

    avg = 1.0 * sum / n;

    if (avg == 5) {
        puts("Named");
    }
    else if (f == 0) {
        puts("None");
    }
    else if (avg >= 4.5) {
        puts("High");
    }
    else {
        puts("Common");
    }

    return 0;
}