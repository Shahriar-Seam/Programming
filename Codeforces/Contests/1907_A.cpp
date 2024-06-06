#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, i;
    char s[3];
    char j;

    cin >> t;

    while (t--) {
        cin >> s;

        for (i = 1; i <= 8; i++) {
            if (s[1] == i + '0') {
                continue;
            }
            else {
                cout << s[0] << i << "\n";
            }
        }

        for (j = 'a'; j <= 'h'; j++) {
            if (s[0] == j) {
                continue;
            }
            else {
                cout << j << s[1] << "\n";
            }
        }
    }

    return 0;
}