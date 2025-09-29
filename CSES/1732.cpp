#include <bits/stdc++.h>

using namespace std;

vector <int> prefix_function(string &s)
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

    string n;
    int i, j;
    vector <int> l, pi;

    cin >> n;

    pi = prefix_function(n);

    for (i = n.size() - 1, j = pi[i]; j > 0; ) {
        while (j > 0 && n[i] != n[j - 1]) {
            j = pi[j - 1];
        }

        l.push_back(j);
        j = pi[j - 1];
    }

    sort(l.begin(), l.end());

    for (auto &it : l) {
        cout << it << " ";
    }

    cout << "\n";

    return 0;
}