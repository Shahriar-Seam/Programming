#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i;
    string s, news = "";

    cin >> n >> s;

    for (i = 0; i < n; ) {
        if (s[i] == '1') {
            news += '1';

            i++;
        }
        else {
            while (i < n && s[i] != '1') {
                i++;
            }

            news += '0';
        }
    }

    s = "";

    for (i = 0; i < (int) news.size(); ) {
        if ((i < (int) news.size() - 2) && news[i] == '1' && news[i + 1] == '0' && news[i + 2] == '1') {
            s += '1';

            i += 3;
        }
        else {
            s += news[i];
            i++;
        }
    }

    if (count(s.begin(), s.end(), '1') > count(s.begin(), s.end(), '0')) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
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