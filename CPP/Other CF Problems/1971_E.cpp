#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, k, q, d, i, pos, mins;
    
    cin >> n >> k >> q;

    int signs[k + 1];
    int minutes[k + 1];

    signs[0] = minutes[0] = 0;

    for (i = 1; i <= k; i++) {
        cin >> signs[i];
    }

    for (i = 1; i <= k; i++) {
        cin >> minutes[i];
    }

    while (q--) {
        cin >> d;

        pos = lower_bound(signs + 1, signs + k + 1, d) - signs - 1;

        mins = minutes[pos] + (d - signs[pos]) * 1.0 * (minutes[pos + 1] - minutes[pos]) / (signs[pos + 1] - signs[pos]);

        cout << mins << " ";
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