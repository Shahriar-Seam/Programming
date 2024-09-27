#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i;
    int even_max = 0, odd_max = 0;
    int even_count = 0, odd_count = 0;

    cin >> n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    for (i = 0; i < n; i++) {
        if (i % 2 == 0) {
            if (v[i] > even_max) {
                even_max = v[i];
            }

            even_count++;
        }
        else {
            if (v[i] > odd_max) {
                odd_max = v[i];
            }

            odd_count++;
        }
    }

    cout << max(even_count + even_max, odd_count + odd_max) << "\n";
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