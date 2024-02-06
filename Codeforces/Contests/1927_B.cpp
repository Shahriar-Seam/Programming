#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i, temp;
    unordered_map <int, char> m;
    char ch = 'a';

    cin >> n;

    for (i = 0; i < n; i++) {
        cin >> temp;

        if (temp == 0) {
            m[temp] = ch;
            ch++;
        }
        else {
            m[temp] = m[temp - 1];
        }
    }

    for (auto it = m.begin(); it != m.end(); it++) {
        cout << (*it).second;
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