#include <stdio.h>

int is_trapped(int k, int traps[100][2], int n)
{
    int i = 0, j = 0, trapped = 0;

    for (i = k; i >= 1; i--)
    {
        int times = (k - i) * 2;
        for (j = 0; j < n; j++)
        {
            if (traps[j][0] == i && traps[j][1] <= times)
            {
                return 0;
            }
        }
    }
    return 1;
}

int main()
{
    int t = 0, n = 0, traps[100][2], i, j, k = 1;

    scanf("%d", &t);
    for (i = 0; i < t; i++)
    {
        scanf("%d", &n);
        for (j = 0; j < n; j++)
        {
            scanf("%d%d", &traps[j][0], &traps[j][1]);
        }
        for (k = 1; k > 0; k++)
        {
            int trapped = is_trapped(k, traps, n);
            if (trapped == 0)
            {
                k--;
                break;
            }
        }
        printf("\n%d", k);
    }

        return 0;
}