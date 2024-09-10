#include <bits/stdc++.h>

using namespace std;

int possible(long long x, long long w, long long h, long long n)
{
    return (floor(x / (1.0 * w)) * floor(x / (1.0 * h))) >= n;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long w, h, n;
    long long l = 0, r = 1e18, m;
    long long x = r;

    cin >> w >> h >> n;

    while (l <= r) {
        m = l + (r - l) / 2;

        if (possible(m, w, h, n)) {
            r = m - 1;
            x = min(x, m);
        }
        else {
            l = m + 1;
        }
    }

    cout << x << "\n";

    return 0;
}