#include <bits/stdc++.h>

using namespace std;

vector <int> prefix_function(string s)
{
    int n = s.size(), i, j;
    vector <int> pi(n, 0);

    for (i = 1; i < n; i++) {
        j = pi[i - 1];

        while (j > 0 && s[i] != s[j]) {
            j = pi[j - 1];
        }

        if (s[i] == s[j]) {
            j++;
        }

        pi[i] = j;
    }

    return pi;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int count = 0;
    string n, m;

    cin >> n >> m;

    for (auto &it : prefix_function(m + "0" + n)) {
        count += it == m.size();
    }

    cout << count << "\n";

    return 0;
}