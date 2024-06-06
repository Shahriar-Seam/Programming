#include <stdio.h>

int main()
{
    int i;

    for (i = 0; i < 1000; i++) {
        if ((i & (i - 1)) == 0) {
            printf("%d\n", i);
        }
    }

    return 0;
}