#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n, i;
    string s;

    cin >> t;

    while (t--) {
        cin >> n;
        cin >> s;

        for (i = 0; i < n; i++) {
            if (s[i] == 'U') {
                s[i] = 'D';
            }
            else if (s[i] == 'D') {
                s[i] = 'U';
            }
        }

        cout << s << "\n";
    }

    return 0;
}