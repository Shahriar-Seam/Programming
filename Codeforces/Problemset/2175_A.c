#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define read(n) scanf("%d", n)
#define write(n) printf("%d\n", n)

void solve()
{
    int n, i, count = 0;

    read(&n);

    int arr[n];
    bool marked[1005] = {};

    for (i = 0; i < n; i++) {
        read(arr + i);

        marked[arr[i]] = true;
    }

    for (i = 0; i < 1005; i++) {
        if (marked[i]) {
            count++;
        }
    }

    while (true) {
        if (!marked[count]) {
            marked[count++] = true;
        }
        else {
            break;
        }
    }

    write(count);
}

int32_t main()
{
    int32_t t;

    scanf("%d", &t);

    while (t--) {
        solve();
    }

    return 0;
}