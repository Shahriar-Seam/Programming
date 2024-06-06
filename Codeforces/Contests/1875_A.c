#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t, i;
    int a, b, n;
    unsigned long long int time;
    int *tools;

    scanf("%d", &t);

    while (t--) {
        scanf("%d %d %d", &a, &b, &n);

        time = b;
        tools = (int *) malloc(sizeof(int) * n);

        for (i = 0; i < n; i++) {
            scanf("%d", &tools[i]);
        }

        for (i = 0; i < n; i++) {
            if (tools[i] < a) {
                time += tools[i];
            }
            else time += a - 1;
        }

        free(tools);

        printf("%llu\n", time);
    }

    return 0;
}