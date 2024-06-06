#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, i;
    string s;

    cin >> t;

    while (t--) {
        cin >> s;

        if (s[0] == '?') {
            s[0] = '0';
        }

        for (i = 1; i < s.size(); i++) {
            if (s[i] == '?') {
                s[i] = s[i - 1];
            }
        }

        cout << s << "\n";
    }

    return 0;
}