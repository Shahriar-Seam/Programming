#include <stdio.h>
#include <string.h>

#define yes printf("YES\n")
#define no printf("NO\n")

int main()
{
    int t;
    char str[4];

    scanf("%d", &t);

    while (t--) {
        scanf (" %s", str);

        if (strcmp(str, "abc") == 0) {
            yes;
        }
        else if (strcmp(str, "cba") == 0) {
            yes;
        }
        else if (strcmp(str, "bac") == 0) {
            yes;
        }
        else if (strcmp(str, "acb") == 0) {
            yes;
        }
        else {
            no;
        }
    }

    return 0;
}