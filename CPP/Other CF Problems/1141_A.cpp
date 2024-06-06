#include <bits/stdc++.h>

using namespace std;

long long power(long long n, long long p)
{
    long long i, num = 1;

    for (i = 0; i < p; i++) {
        num *= n;
    }

    return num;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, m, x, y, num, f = 0, moves = 0;

    cin >> n >> m;

    for (x = 0; x <= 30; x++) {
        for (y = 0; y <= 20; y++) {
            num = n * power(2, x) * power(3, y);

            if (num == m) {
                f = 1;
                moves = x + y;
            }
            else if (num > m) {
                break;
            }
        }
    }

    f ? cout << moves : cout << -1;

    return 0;
}