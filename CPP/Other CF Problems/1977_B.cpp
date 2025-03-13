#include <bits/stdc++.h>

using namespace std;

string to_bin(int x)
{
    string s;

    while (x > 0) {
        s += ('0' + x % 2);
        x /= 2;
    }

    s += '0';

    return s;
}

int to_int(vector <int> &v)
{
    int i, val = 0;

    for (i = 0; i < v.size(); i++) {
        val += v[i] * (1 << i);
    }

    return val;
}

void solve()
{
    int x, i, j;

    cin >> x;

    string s = to_bin(x);
    vector <int> v(s.size(), 0);

    for (i = 0; i < s.size() - 1; i++) {
        if (s[i] == '0') {
            continue;
        }
        else if (s[i] == '1') {
            if (s[i + 1] == '1') {
                v[i] = -1;

                for (j = i + 1; j < s.size() - 1; j++) {
                    if (s[j] == '1') {
                        v[j] = 0;
                    }
                    else {
                        break;
                    }
                }

                s[j] = '1';
                v[j] = 1;
                i = j - 1;
            }
            else {
                v[i] = 1;
            }
        }
    }

    cout << v.size() << "\n";

    for (auto it : v) {
        cout << it << " ";
    }

    cout << "\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int32_t t, i;

    cin >> t;

    for (i = 1; i <= t; i++) {
        // cout << "Case " << i << ": ";

        solve();
    }

    return 0;
}