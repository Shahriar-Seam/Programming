#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, i, len, cnt_b, cnt_B;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;

        len = s.size();
        cnt_b = cnt_B = 0;
        
        for (i = len - 1; i >= 0; i--) {
            if (s[i] == 'b') {
                cnt_b++;
                s[i] = ' ';
            }
            else if (s[i] == 'B') {
                cnt_B++;
                s[i] = ' ';
            }

            if (cnt_b && islower(s[i])) {
                s[i] = ' ';
                cnt_b--;
            }
            else if (cnt_B && isupper(s[i])) {
                s[i] = ' ';
                cnt_B--;
            }
        }

        for (i = 0; i < len; i++) {
            if (s[i] != ' ') {
                cout << s[i];
            }
        }

        cout << "\n";
    }

    return 0;
}
