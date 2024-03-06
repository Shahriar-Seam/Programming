#include <bits/stdc++.h>

using namespace std;

void solve()
{
    string s;
    int p, sum = 0, i;

    cin >> s >> p;

    for (i = s.size() - 1; i >= 0; i--) {
        sum += s[i] - 'a';
    }

    sort(s.begin(), s.end());

    
    for (i = s.size() - 1; sum > p; i--) {
        sum -= s[i] - 'a';
    }

    s = s.substr(0, max(0, i));

    cout << s << "\n";
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