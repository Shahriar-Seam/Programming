#include <stdio.h>

int main()
{
    int t, n, i, j;

    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        for (i = 0; i < n; i++) {
            if (i % 2 == 0) {
                for (j = 0; j < n; j++) {
                    printf(j % 2 == 0 ? "##" : "..");
                }

                puts("");
                
                for (j = 0; j < n; j++) {
                    printf(j % 2 == 0 ? "##" : "..");
                }
            }
            else {
                for (j = 0; j < n; j++) {
                    printf(j % 2 == 0 ? ".." : "##");
                }

                puts("");

                for (j = 0; j < n; j++) {
                    printf(j % 2 == 0 ? ".." : "##");
                }
            }

            printf("\n");
        }
    }

    return 0;
}