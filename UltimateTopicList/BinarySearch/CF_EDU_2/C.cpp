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

    cin >> n >> x >> y;

    n++;

    long long l = 0, r = 10 * n + 5, m;

    while (r - l > 1) {
        m = l + (r - l) / 2;

        if (possible(m)) {
            r = m;
        }
        else {
            l = m;
        }
    }

    cout << r << "\n";

    return 0;
}