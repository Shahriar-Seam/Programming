#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, i, moves = LONG_LONG_MAX;

    cin >> n;

    for (i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            moves = min(moves, i + (n / i) - 2);
        }
    }

    cout << moves;

    return 0;
}