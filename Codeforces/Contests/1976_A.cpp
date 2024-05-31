#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    string s1, s2;

    cin >> n >> s1;

    s2 = s1;

    sort(s1.begin(), s1.end());

    cout << ((s1 == s2) ? "YES\n" : "NO\n");
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