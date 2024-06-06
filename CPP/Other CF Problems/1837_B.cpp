#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n, cnt, cost, i;
    string s;

    cin >> t;

    while (t--) {
        cin >> n >> s;

        cost = 2;
        cnt = 1;

        for (i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                cnt++;
            }
            else {
                cost = max(cost, cnt + 1);
                cnt = 1;
            }
        }

        cost = max(cost, cnt + 1);

        cout << cost << "\n";
    }

    return 0;
}