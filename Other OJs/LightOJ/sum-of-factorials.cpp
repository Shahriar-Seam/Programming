#include <bits/stdc++.h>

using namespace std;

#define int long long

const int sz = 20;
vector <int> f(sz, 0);

void fill()
{
    int i;

    for (i = 1, f[0] = 1; i < sz; i++) {
        f[i] = f[i - 1] * i;
    }
}

void solve()
{
    int n, i, mask, sum;

    cin >> n;

    for (mask = 1; mask < (1LL << sz); mask++) {
        for (i = 0, sum = 0; i < sz; i++) {
            if (mask & (1LL << i)) {
                sum += f[i];
            }
        }

        if (sum == n) {
            break;
        }
    }

    if (mask == (1LL << sz)) {
        cout << "impossible\n";
    }
    else {
        string s;

        for (i = 0; i < sz; i++) {
            if (mask & (1LL << i)) {
                s += to_string(i) + "!+";
            }
        }

        s.pop_back();

        cout << s << "\n";
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    fill();

    int32_t t, i;

    cin >> t;

    for (i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";

        solve();
    }

    return 0;
}