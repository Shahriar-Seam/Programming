#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i, k, temp;
    set <int> s;

    cin >> n;

    for (i = 0; i < n; i++) {
        cin >> k;

        while (k--) {
            cin >> temp;

            s.insert(temp);
        }
    }

    n == 1 ? cout << "0\n" : cout << s.size() - 1 << "\n";

    s.clear();
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