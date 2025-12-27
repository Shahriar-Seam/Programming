#include <bits/stdc++.h>

using namespace std;

int lps(string &s, int l, int r, vector <vector <int> > &memo)
{
    if (l > r) {
        return 0;
    }

    if (l == r) {
        return memo[l][r] = 1;
    }

    if (memo[l][r] == -1) {
        if (s[l] == s[r]) {
            memo[l][r] = lps(s, l + 1, r - 1, memo) + 2;
        }
        else {
            memo[l][r] = max(lps(s, l + 1, r, memo), lps(s, l, r - 1, memo));
        }
    }

    return memo[l][r];
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s, p, prefix, suffix;
    char c;
    int n, l, r;

    cin >> s;

    n = s.size();

    if (n > 2600) {
        for (c = 'a'; c <= 'z'; c++) {
            if (count(s.begin(), s.end(), c) >= 100) {
                cout << string(100, c) << "\n";

                break;
            }
        }
    }
    else {
        vector <vector <int> > memo(n, vector <int> (n, -1));

        lps(s, 0, n - 1, memo);

        l = 0;
        r = n - 1;

        while (l < r) {
            if (s[l] == s[r]) {
                prefix += s[l];
                suffix += s[r];

                l++;
                r--;
            }
            else if (memo[l + 1][r] > memo[l][r - 1]) {
                l++;
            }
            else {
                r--;
            }
        }

        reverse(suffix.begin(), suffix.end());

        if (l == r) {
            prefix += s[l];
        }

        p = prefix + suffix;

        if (p.size() > 100) {
            if (p.size() & 1) {
                p.erase(p.begin() + p.size() / 2);
            }
            
            while (p.size() > 100) {
                p.pop_back();
                p.erase(p.begin());
            }
        }

        cout << p << "\n";
    }

    return 0;
}