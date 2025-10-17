#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int a, b, i;
    vector <int> x;

    cin >> a >> b;

    bitset <30> A(a), B(b);

    for (i = 0; i <= 30; i++) {
        if (A[i] != B[i]) {
            x.push_back(1LL << i);
        }
    }

    for (auto &it : x) {
        if (a < it) {
            cout << - 1 << "\n";

            return;
        }

        a ^= it;
    }

    cout << x.size() << "\n";
    
    for (auto &it : x) {
        cout << it << " ";
    }

    cout << "\n";
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