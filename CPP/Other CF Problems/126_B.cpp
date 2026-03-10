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

    string s, t;
    int n;

    cin >> s;

    n = s.size();

    vector <int> pi = prefix_function(s);

    if (pi[n - 1] == 0) {
        t = "Just a legend";
    }
    else {
        if (count(pi.begin(), pi.end(), pi[n - 1]) >= 2) {
            t = s.substr(0, pi[n - 1]);
        }
        else {
            if (pi[pi[n - 1] - 1] == 0) {
                t = "Just a legend";
            }
            else {
                t = s.substr(0, pi[pi[n - 1] - 1]);
            }
        }
    }

    cout << t << "\n";

    return 0;
}