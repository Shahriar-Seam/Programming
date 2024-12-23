#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, m, k;

    cin >> n >> m >> k;

    vector <int> a(m), q(k);

    for (auto &it : a) {
        cin >> it;
    }

    for (auto &it : q) {
        cin >> it;
    }

    for (auto it : a) {
        if (binary_search(q.begin(), q.end(), it)) {
            if (k - 1 >= n - 1) {
                cout << 1;
            }
            else {
                cout << 0;
            }
        }
        else {
            if (k >= n - 1) {
                cout << 1;
            }
            else {
                cout << 0;
            }
        }
    }

    cout << "\n";
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