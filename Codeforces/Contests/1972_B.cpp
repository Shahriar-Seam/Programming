#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i;
    string s;

    cin >> n >> s;

    puts(count(s.begin(), s.end(), 'U') % 2 == 1 ? "YES" : "NO");
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