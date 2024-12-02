#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int n, k, i, zero = 0, one = 0, j = 0, f = 0;
    int diff = 0;
    string s;

    cin >> n >> k >> s;

    for (i = 0; i < n; i++) {
        zero += (s[i] == '0');
        one += (s[i] == '1');
    }

    i = 0;

    for (i = 0; i < n; i++) {
        if (diff + j * one - j * zero >= k) {
            cout << j + 1 << "\n";

            return;
        }

        if (s[i] == '1') {
            if (diff + j + (one - 1) * (j + 1) - zero * (j + 1) >= k) {
                cout << j + 2 << "\n";

                return;
            }
            else {
                diff += j;
                one--;

                j++;
            }
        }
        else {
            if (diff + j + one * (j + 1) - (zero - 1) * (j + 1) >= k) {
                cout << j + 2 << "\n";

                return;
            }
            else {
                diff -= j;
                zero--;

                j++;
            }
        }
    }

    cout << "-1\n";

}

int32_t main()
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