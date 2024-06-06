#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n, k, i, cnt;
    string s;
    map <char, int> m;

    cin >> t;

    while (t--) {
        cin >> n >> k >> s;

        cnt = 0;

        for (i = 0; i < n; i++) {
            m[s[i]]++;
        }

        for (auto it = m.begin(); it != m.end(); it++) {
            if ((*it).second % 2 == 1) {
                cnt++;
            }
        }

        if (cnt > k + 1) {
            puts("NO");
        }
        else {
            puts("YES");
        }

        m.clear();
    }

    return 0;
}