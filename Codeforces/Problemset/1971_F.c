#include <stdio.h>

void solve()
{
    int r, x, y, h, count = 0;

    scanf("%d", &r);
    
    for (x = 0, y = r; x <= r; x++) {
        while (x * x + y * y >= (r + 1) * (r + 1)) {
            y--;
        }

        h = y;

        while (x * x + h * h >= r * r && h > 0) {
            h--;
            
            count++;
        }
    }

    printf("%d\n", count * 4);
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