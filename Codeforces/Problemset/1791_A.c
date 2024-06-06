#include <stdio.h>
#include <string.h>

#define yes printf("YES\n")
#define no printf("NO\n")

int is_present(char cf[], char ch)
{
    int i;

    for (i = 0; i < 10; i++) {
        if (cf[i] == ch) return 1;
    }

    return 0;
}

int main()
{
    int t;
    char ch;
    char cf[] = "codeforces";

    scanf("%d", &t);

    while (t--) {
        getchar();
        ch = getchar();

        if (is_present(cf, ch)) yes;
        else no;
    }    

    return 0;
}