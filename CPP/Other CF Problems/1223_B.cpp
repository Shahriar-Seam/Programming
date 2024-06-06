#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, len, i, j, f;
    string s1, s2;

    cin >> t;

    while (t--) {
        cin >> s1 >> s2;

        len = s1.size();
        f = 0;

        for (i = 0; i < len; i++) {
            for (j = 0; j < len; j++) {
                if (s1[i] == s2[j]) {
                    f = 1;
                    break;
                }
            }

            if (f) {
                break;
            }
        }

        f ? cout << "YES\n" : cout << "NO\n";
    }

    return 0;
}