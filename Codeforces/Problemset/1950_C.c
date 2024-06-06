#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void solve()
{
    char str[6];
    int hh, mm;

    scanf(" %s", str);

    sscanf(str, "%d:%d", &hh, &mm);

    if (hh >= 12) {
        if (hh > 12) {
            hh -= 12;
        }

        if (hh < 10) {
            if (mm < 10) {
                printf("0%d:0%d PM\n", hh, mm);
            }
            else {
                printf("0%d:%d PM\n", hh, mm);
            }
        }
        else {
            if (mm < 10) {
                printf("%d:0%d PM\n", hh, mm);
            }
            else {
                printf("%d:%d PM\n", hh, mm);
            }
        }
    }
    else {
        if (hh == 0) {
            hh = 12;
        }

        if (hh < 10) {
            if (mm < 10) {
                printf("0%d:0%d AM\n", hh, mm);
            }
            else {
                printf("0%d:%d AM\n", hh, mm);
            }
        }
        else {
            if (mm < 10) {
                printf("%d:0%d AM\n", hh, mm);
            }
            else {
                printf("%d:%d AM\n", hh, mm);
            }
        }
    }
}

int main()
{
    int t;

    scanf("%d", &t);

    while (t--) {
        solve();
    }
}