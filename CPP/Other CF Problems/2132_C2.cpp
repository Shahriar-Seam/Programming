#include <bits/stdc++.h>

using namespace std;

#define int long long

int bin_exp(int b, int p)
{
    int result = 1;

    while (p > 0) {
        if (p & 1) {
            result = result * b;
        }

        b = b * b;

        p >>= 1;
    }

    return result;
}

void solve()
{
    int n, k, cost = 0, i, j, total = 0, cnt, f, p, m;
    int it = 0;
    vector <int> v;

    cin >> n >> k;

    while (n > 0) {
        v.push_back(n % 3);

        n /= 3;
    }

    total = accumulate(v.begin(), v.end(), 0LL);

    if (total > k) {
        cout << -1 << "\n";

        return;
    }

    for (i = v.size() - 1; i > 0; i--) {
        if (v[i]) {
            cnt = v[i];

            
            while (cnt--) {
                f = 0;

                for (j = i - 1; j >= 0; j--) {
                    p = bin_exp(3, i - j);
                    it++;

                    if (total - 1 + p <= k) {
                        m = (k - total) / (p - 1);

                        m = min(m, v[i]);

                        v[i] -= m;
                        v[j] += m * p;

                        total = total - m + m * p;

                        f = 1;

                        break;
                    }
                }

                if (!f || !v[i]) {
                    break;
                }
            }
        }
    }

    for (i = 0; i < v.size(); i++) {
        cost += v[i] * (bin_exp(3, i + 1) + i * bin_exp(3, i - 1));
    }

    cout << cost << "\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int32_t t, i;

    cin >> t;

    for (i = 1; i <= t; i++) {
        // cout << "Case " << i << ": ";

        solve();
    }

    return 0;
}