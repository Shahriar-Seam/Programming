#include <stdio.h>

int main()
{
    int n, count_25 = 0, count_50 = 0, temp, f = 1;

    scanf("%d", &n);

    while (n--) {
        scanf("%d", &temp);

        if (temp == 25) {
            count_25++;
        }
        else if (temp == 50) {
            count_25--;
            count_50++;
        }
        else if (temp == 100) {
            if (count_50 > 0) {
                count_50--;
                count_25--;
            }
            else {
                count_25 -= 3;
            }
        }

        if (count_25 < 0) {
            f = 0;
            break;
        }
    }

    puts(f == 1 ? "YES" : "NO");

    return 0;
}