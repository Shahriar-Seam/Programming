#include <bits/stdc++.h>

using namespace std;

void solve()
{
    long long x, y, z, k;
    long long a, b, c;

    cin >> x >> y >> z >> k;

    for (a = x; a > 0; a--) {
        if (k % a == 0) {
            k /= a;

            break;
        }
    }

    for (b = y; b > 0; b--) {
        if (k % b == 0) {
            k /= b;

            break;
        }
    }

    c = k;
    
    cout << (max(0LL, x - a) + 1) * (max(0LL, y - b) + 1) * (max(-1LL, z - c) + 1) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}