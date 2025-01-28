#include <bits/stdc++.h>

using namespace std;

int len(int n)
{
    int l = 0;

    while (n > 0) {
        n >>= 1;

        l++;
    }

    return l;
}

void solve()
{
    int n, a, b, i;

    cin >> n;

    a = 0, b = n;

    for (i = 0; i < 31; i++) {
        if (n & (1 << i)) {
            a |= (1 << i);

            b &= ~(1 << i);

            break;
        }
    }

    cout << a << " " << b << "\n";
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