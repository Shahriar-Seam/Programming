#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i;
    string s;

    cin >> n;

    vector <string> v(n);

    for (auto &it : v) {
        cin >> it;
    }
    
    for (auto it = v.rbegin(); it != v.rend(); it++) {
        s = *it;

        for (i = 0; i < s.size(); i++) {
            if (s[i] == '#') {
                cout << i + 1 << " ";
                break;
            }
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