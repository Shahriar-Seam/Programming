#include <bits/stdc++.h>

using namespace std;

int n, x, y;

bool possible(long long m)
{
    return (m / x) + (m / y) >= n;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i;

    cin >> n >> x >> y;

    n--;

    long long l = 0, r = 10 * n + 5, m;

    for (i = 0; i < 100; i++) {
        m = l + (r - l) / 2;

        if (possible(m)) {
            r = m;
        }
        else {
            l = m;
        }
    }

    cout << r + min(x, y) << "\n";

    return 0;
}