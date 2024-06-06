#include <bits/stdc++.h>

using namespace std;

void solve()
{
    string s;
    int p, sum = 0, i, f = 0;
    map <char, int> m;

    cin >> s >> p;

    for (i = 0; i < s.size(); i++) {
        m[s[i]]++;
        sum += s[i] - 'a' + 1;
    }

    for (auto it = m.rbegin(); it != m.rend(); it++) {
        while ((*it).second > 0) {
            if (sum > p) {
                sum -= (*it).first - 'a' + 1;
                (*it).second--;
            }
            else {
                f = 1;
                break;
            }
        }

        if (f == 1) {
            break;
        }
    }

    for (i = 0; i < s.size(); i++) {
        if (m[s[i]] > 0) {
            cout << s[i];
            m[s[i]]--;
        }
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