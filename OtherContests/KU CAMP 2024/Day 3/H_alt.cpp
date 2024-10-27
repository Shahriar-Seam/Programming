#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i, f = 1, s = int(1e9);

    cin >> n;

    vector <int> l(n), r(n);

    for (i = 0; i < n; i++) {
        cin >> l[i] >> r[i];
    }

    for (i = 1; i < n; i++) {
        l[i] = max(l[i], l[i - 1] + 1);
        r[i] = min(r[i], r[i - 1] + 1);
    }

    for (i = n - 1; i > 0; i--) {
        if (l[i] > r[i]) {
            f = 0;
            break;
        }
    }

    s = l[n - 1] - n + 1;

    if (f == 1) {
        cout << s << "\n";
    }
    else {
        cout << "I'm Stuck :(\n";
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