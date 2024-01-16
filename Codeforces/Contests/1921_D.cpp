#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, m, i, j = 0, temp, d = 0;
    vector <int> a, b;

    cin >> n >> m;

    for (i = 0; i < n; i++) {
        cin >> temp;

        a.push_back(temp);
    }
    
    for (i = 0; i < m; i++) {
        cin >> temp;

        b.push_back(temp);
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), greater<int>());

    for (i = 0; i < n; i++) {
        if (abs(b[i] - a[i]) > abs(b[m - j - 1] - a[i])) {
            d += abs(b[i] - a[i]);
        }
        else {
            d += abs(b[m - j - 1] - a[i]);
            j++;
        }
    }

    cout << d << "\n";
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