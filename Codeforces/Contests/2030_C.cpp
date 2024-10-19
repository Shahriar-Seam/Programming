#include <bits/stdc++.h>

using namespace std;

int to_int(char c)
{
    return c - '0';
}

void solve()
{
    int n, i, j = 0, result;
    string s;
    stack <int> st;

    cin >> n >> s;

    puts(count(s.begin(), s.end(), '0') > count(s.begin(), s.end(), '1') ? "NO" : "YES");
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