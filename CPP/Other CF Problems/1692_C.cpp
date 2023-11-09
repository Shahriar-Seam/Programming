#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, i, j, cnt, f, r, c;
    string s[8];

    cin >> t;
    
    while (t--) {
        for (i = 0; i < 8; i++) {
            cin >> s[i];
        }

        f = 0;

        for (i = 0; i < 8; i++) {
            cnt = 0;

            for (j = 0; j < 8; j++) {
                if (s[i][j] == '#') {
                    cnt++;
                    r = i + 1;
                    c = j + 1;
                }
            }

            if (cnt == 2) {
                f = 1;
            }

            else if (f == 1 && cnt == 1) {
                break;
            }
        }

        cout << r << " " << c << "\n";
    }

    return 0;
}