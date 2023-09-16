#include <stdio.h>
#define yes printf("YES\n")
#define no printf("NO\n")

int main()
{
    int t, n;
    char str[102];

    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);
        scanf(" %s", str);

        if (n == 1) {
            yes;
        }
        else if (n == 2) {
            if (str[0] == str[1]) {
                no;
            }
            else {
                yes;
            }
        }
        else {
            no;
        }
    }

    return 0;
}