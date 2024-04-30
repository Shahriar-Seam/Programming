#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int sum = 0, l = -1, r = -1, i;
    string s;

    cin >> s;

    reverse(s.begin(), s.end());

    for (i = 0; i < s.length(); i++) {
        if (l == -1 && s[i] == '0') {
            l = i;
        }
        else if (l != -1 && s[i] == '1') {
            sum += i - l + 1;

            swap(s[i], s[l]);

            i = l;

            l = -1;
        }
    }

    cout << sum << "\n";
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