#include <bits/stdc++.h>

using namespace std;

array <vector <int>, 2> manacher(const string &s)
{
    int n = s.size();

    array <vector <int>, 2> p = {vector <int> (n + 1), vector <int> (n)};

    for (int z = 0; z < 2; z++) {
        for (int i = 0, l = 0, r = 0; i < n; i++) {
            int t = r - i + !z;

            if (i < r) {
                p[z][i] = min(t, p[z][l + t]);
            }

            int L = i - p[z][i], R = i + p[z][i] - !z;

            while (L >= 1 && R + 1 < n && s[L - 1] == s[R + 1]) {
                p[z][i]++, L--, R++;
            }

            if (R > r) {
                l = L, r = R;
            }
        }
    }

    return p;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s, t;
    int max_len = 0, max_ind = 0, i, n;

    cin >> s;

    n = s.size();

    array <vector <int>, 2> p = manacher(s);

    for (i = 0; i <= n; i++) {
        if (p[0][i] * 2 > max_len) {
            max_len = p[0][i] * 2;
            max_ind = i;
        }
    }
    
    for (i = 0; i < n; i++) {
        if ((p[1][i] + 1) * 2 - 1 > max_len) {
            max_len = (p[1][i] + 1) * 2 - 1;
            max_ind = i;
        }
    }
    
    for (i = max_ind - 1; i > max_ind - (max_len + 1) / 2; i--) {
        t += s[i];
    }

    if (!(max_len & 1)) {
        t += s[i];
    }

    reverse(t.begin(), t.end());

    for (i = max_ind; i < max_ind + (max_len + 1) / 2; i++) {
        t += s[i];
    }

    cout << t << "\n";

    return 0;
}