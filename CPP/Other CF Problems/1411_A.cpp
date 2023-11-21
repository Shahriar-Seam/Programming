#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n, i, cnt;
    string s;

    cin >> t;

    while (t--) {
        cin >> n;
        cin >> s;

        cnt = 0;

        for (i = n - 1; i >= 0; i--) {
            if (s[i] != ')') {
                cnt = i + 1;
                break;
            }
        }

        if (n - cnt > cnt) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }

    return 0;
}