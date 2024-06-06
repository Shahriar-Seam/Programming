#include <stdio.h>

int main()
{
    int n, temp, i, biceps, back, chest;

    biceps = back = chest = 0;

    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        scanf("%d", &temp);

        if (i % 3 == 1) {
            chest += temp;
        }
        else if (i % 3 == 2) {
            biceps += temp;
        }
        else {
            back += temp;
        }
    }

    if (chest > biceps && chest > back) {
        printf("chest");
    }
    else if (biceps > chest && biceps > back) {
        printf("biceps");
    }
    else {
        printf("back");
    }

    return 0;
}