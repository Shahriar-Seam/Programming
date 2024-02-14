#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, sum = 2, i;
    int fib[42] = {};

    cin >> n;

    fib[0] = fib[1] = 1;

    for (i = 2; i < n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];

        sum += fib[i];
    }

    if (n == 0) {
        cout << 0;
    }
    else if (n == 1) {
        cout << 1;
    }
    else if (n == 2) {
        cout << 2;
    }
    else {
        cout << sum;
    }

    return 0;
}