#include <bits/stdc++.h>

using namespace std;

void solve()
{
    long long n, temp, max_odd = 0, i, extra = 0;
    vector <long long> even;

    cin >> n;

    for (i = 0; i < n; i++) {
        cin >> temp;

        if (temp % 2 == 0) {
            even.push_back(temp);
        }
        else {
            max_odd = max(max_odd, temp);
        }
    }

    if (even.size() == 0 || even.size() == n) {
        cout << 0 << "\n";

        return;
    }

    sort(even.begin(), even.end());

    for (i = 0; i < even.size(); i++) {
        if (even[i] <= max_odd) {
            max_odd += even[i];
        }
        else {
            extra = 1;

            max_odd += 2 * even[i];
        }
    }

    cout << even.size() + extra << "\n";
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