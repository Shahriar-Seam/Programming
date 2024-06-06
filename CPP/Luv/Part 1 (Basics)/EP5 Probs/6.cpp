#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, i, cnt;
    string j, s;

    cin >> t;

    while (t--) {
        cin >> j >> s;

        cnt = 0;

        for (i = 0; s[i] != '\0'; i++) {
            if (j.find(s[i]) != string::npos) {
                cnt++;
            }
        }

        cout << cnt << "\n";
    }

    return 0;
}