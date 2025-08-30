#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve(int32_t n)
{
    vector <int> v(n);
    int i, j, prod, max_prod = 0;

    for (auto &it : v) {
        cin >> it;
    }

    for (i = 0; i < n; i++) {
        prod = 1;

        for (j = i; j < n; j++) {
            prod *= v[j];

            max_prod = max(max_prod, prod);
        }
    }

    cout << "The maximum product is " << max_prod << ".\n\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int32_t n = 0, i = 1;

    while (cin >> n) {
        cout << "Case #" << i++ << ": ";

        solve(n);
    }

    return 0;
}