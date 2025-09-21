#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    int n, i, j, f, l = 0;

    cin >> s;

    n = s.size();

    reverse(s.begin(), s.end());

    for (i = 0; i < n; i++) {
        f = 1;

        for (j = 0; j <= i / 2; j++) {
            if (s[j] != s[i - j]) {
                f = 0;

                break;
            }
        }

        if (f) {
            l = i + 1;
        }
    }

    reverse(s.begin(), s.end());

    for (i = n - l - 1; i >= 0; i--) {
        s += s[i];
    }

    cout << s << "\n";

    return 0;
}