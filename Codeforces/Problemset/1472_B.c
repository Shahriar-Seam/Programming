#include <stdio.h>

#define yes printf("YES\n")
#define no printf("NO\n")

int main()
{
    int t, n;

    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        int count1 = 0, count2 = 0, a;

        while (n--) {
            scanf("%d", &a);

            if (a == 2) {
                count2++;
            }
            else {
                count1++;
            }
        }

        if (count1 % 2 == 1) {
            no;
        }
        else if (count1 > 0 && (count1 % 2 == 0)) {
            yes;
        }
        else if (count2 % 2 == 0) {
            yes;
        }
        else {
            no;
        }
    }

    return 0;
}