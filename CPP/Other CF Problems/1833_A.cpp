#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i;
    string s, temp;
    set <string> ss;

    cin >> n >> s;

    for (i = 0; i < n - 1; i++) {
        temp = s.substr(i, 2);

        ss.insert(temp);
    }

    cout << ss.size() << "\n";
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