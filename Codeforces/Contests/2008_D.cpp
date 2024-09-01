#include <bits/stdc++.h>

using namespace std;

int recurse(vector <int> &v, int i, string &s, vector <int> &memo, set <int> &ss)
{
    // cout << v[i] << " ";

    if (ss.find(v[i]) != ss.end()) {
        return memo[v[i]];
    }
    else {
        ss.insert(v[i]);
    }

    if (v[i] == 1) {
        return s[0] == '0' ? 1 : 0;
    }

    if (memo[v[i]] == 0) {
        if (s[v[i]] == '0') {
            memo[v[i]] = 1;
        }
        memo[v[i]] += recurse(v, v[i], s, memo, ss);
    }
    
    return memo[v[i]];
}

void solve()
{
    int n, i, temp;
    string s;
    set <int> ss;

    cin >> n;

    vector <int> v(n + 1), memo(n + 1, 0);

    for (i = 1; i <= n; i++) {
        cin >> v[i];
    }

    cin >> s;

    for (i = 1; i <= n; i++) {
        ss.clear();
        recurse(v, i, s, memo, ss);
    }

    for (auto it : memo) {
        cout << it << " ";
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