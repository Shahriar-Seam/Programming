#include <bits/stdc++.h>

using namespace std;

int count_flips(string s)
{
    int i, cnt = 0;

    for (i = 1; i < s.length(); i++) {
        if (s[i - 1] == s[i]) {
            cnt++;
        }
    }

    return cnt;
}

void solve()
{
    int n;
    string s;

    cin >> n >> s;

    cout << count_flips(s) << "\n";
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