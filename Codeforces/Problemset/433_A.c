#include <stdio.h>

int main()
{
    int n, temp, count = 0, count2 = 0;

    scanf("%d", &n);

    while (n--) {
        scanf("%d", &temp);

        count += temp == 100;
        count2 += temp == 200;
    }

    if (count % 2 == 0) {
        if (count2 % 2 == 0) {
            puts("YES");
        }
        else if (count > 0) {
            puts("YES");
        }
        else {
            puts("NO");
        }
    }
    else {
        puts("NO");
    }

    return 0;
}