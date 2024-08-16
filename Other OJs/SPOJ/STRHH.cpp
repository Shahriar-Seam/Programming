#include <bits/stdc++.h>

using namespace std;

void solve()
{
    string s;
    int i;

    cin >> s;

    for (i = 0; i < s.size() / 2; i += 2) {
        cout << s[i];
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