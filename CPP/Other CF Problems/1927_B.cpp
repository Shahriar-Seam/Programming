#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i, temp;
    map <int, char> m;

    cin >> n;

    for (i = 0; i < n; i++) {
        cin >> temp;

        if (m[temp] == 0) {
            m[temp] = 'a';
        }

        cout << m[temp];

        m[temp]++;
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