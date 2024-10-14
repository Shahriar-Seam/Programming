#include <stdio.h>
#include <stdlib.h>

void solve()
{
    int n, r, i, temp, happy = 0, rem = 0;
    int *remaining_seats;

    scanf("%d %d", &n, &r);

    for (i = 0; i < n; i++) {
        scanf("%d", &temp);

        happy += temp - (temp % 2);

        rem += temp % 2;

        r -= temp / 2;
    }

    remaining_seats = (int *) calloc(r, sizeof(int));

    for (i = 0; i < rem; i++) {
        remaining_seats[i % r]++;
    }

    for (i = 0; i < r; i++) {
        happy += (remaining_seats[i] == 1);
    }

    printf("%d\n", happy);
}

int main()
{
    int t;

    scanf("%d", &t);

    while (t--) {
        solve();
    }

    return 0;
}