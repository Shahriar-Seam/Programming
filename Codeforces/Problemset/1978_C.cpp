#include <bits/stdc++.h>

using namespace std;

void solve()
{
    long long n, k, i, j, max_sum;

    cin >> n >> k;

    vector <long long> v(n + 1);

    max_sum = (k & 1LL) ? n * (n + 1) : n * n;

    if ((k & 1LL) || k > max_sum) {
        cout << "NO\n";
    }
    else {
        for (i = 1; i <= n; i++) {
            v[i] = i;
        }
        
        for (i = 1, j = n; i < j; i++, j--) {
            if (k >= 2 * (v[j] - v[i])) {
                k -= 2 * (v[j] - v[i]);

                swap(v[i], v[j]);
            }
            if (k < 2) {
                break;
            }
        }

        if (k == 2) {
            swap(v[1], v[2]);
        }
        
        cout << "YES\n";

        for (i = 1; i <= n; i++) {
            cout << v[i] << " ";
        }

        cout << "\n";
    }
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