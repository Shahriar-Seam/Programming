#include <bits/stdc++.h>

using namespace std;

bool remove_and_check(vector <int> &v, int k)
{
    int i;
    vector <int> temp;

    for (auto it : v) {
        if (it != k) {
            temp.push_back(it);
        }
    }

    for (i = 0; i < temp.size() / 2; i++) {
        if (temp[i] != temp[temp.size() - i - 1]) {
            return false;
        }
    }

    return true;
}

void solve()
{
    int n, i;

    cin >> n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    for (i = 0; i < n / 2; i++) {
        if (v[i] != v[n - i - 1]) {
            if (remove_and_check(v, v[i]) || remove_and_check(v, v[n - i - 1])) {
                cout << "YES\n";

                return;
            }
            else {
                cout << "NO\n";

                return;
            }
        }
    }

    cout << "YES\n";
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