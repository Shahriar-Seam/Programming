#include <bits/stdc++.h>

using namespace std;

string x(string s, string t)
{
    int i;
    string x_s;

    for (i = 0; i < s.size(); i++) {
        if (s[i] != t[i]) {
            x_s += '1';
        }
        else {
            x_s += '0';
        }
    }

    return x_s;
}

void solve()
{
    int n, i, j, k, f = 0;
    string s, x_s, max_x_s = "";
    int l, r;

    cin >> s;

    n = s.size();

    l = r = n;

    for (i = 0; i < n; i++) {
        if (s[i] == '0') {
            k = n - i;

            for (j = 0; j < n - k; j++) {
                if (s[j] == '1') {
                    x_s = x(s.substr(i, k), s.substr(j, k));

                    if (x_s > max_x_s) {
                        max_x_s = x_s;
                        l = j + 1;
                        r = j + k;

                        f = 1;
                    }
                }
            }

            if (f) {
                cout << 1 << " " << n << " " << l << " " << r << "\n";

                return;
            }
        }
    }

    cout << 1 << " " << n << " " << l << " " << r << "\n";
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