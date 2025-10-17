#include <bits/stdc++.h>

using namespace std;

vector <int> prefix_function(string &s)
{
    int i, j, n = s.size();
    vector <int> pi(n, 0);

    for (i = 1; i < n; i++) {
        j = pi[i - 1];

        while (j > 0) {
            if (s[i] == s[j]) {
                break;
            }

            j = pi[j - 1];
        }

        if (s[i] == s[j]) {
            j++;
        }

        pi[i] = j;
    }

    return pi;
}

void solve(int n)
{
    int i;
    string needle, haystack, needle_in_haystack;

    cin >> needle >> haystack;

    needle_in_haystack = needle + ' ' + haystack;

    vector <int> pi = prefix_function(needle_in_haystack), pos;

    for (i = 0; i < pi.size(); i++) {
        if (pi[i] == n) {
            pos.push_back(i - 2 * n);
        }
    }

    if (!pos.empty()) {
        for (auto &it : pos) {
            cout << it << "\n";
        }
    }
    else {
        cout << "\n";
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int32_t n;

    while (cin >> n) {
        solve(n);
    }

    return 0;
}