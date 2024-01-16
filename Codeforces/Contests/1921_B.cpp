#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n, i, cnt, a, b;
    string s1, s2;

    cin >> t;

    while (t--) {
        cin >> n;

        cnt = a = b = 0;
        
        cin >> s1 >> s2;

        for (i = 0; i < n; i++) {
            if (s1[i] != s2[i]) {
                if (s1[i] == '1') {
                    a++;
                }
                if (s2[i] == '1')
                {
                    b++;
                }
            }
        }
        cout << max(a, b) << "\n";
    }

    return 0;
}