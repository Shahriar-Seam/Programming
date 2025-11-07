#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i, count = 0, cnt = 0;
    string s, t;

    cin >> n >> s >> t;

    for (i = 0; i < n; i++) {
        if (s[i] < t[i]) {
            count += (n - i) * (cnt + 1);

            cnt = 0;
        }
        else if (s[i] > t[i]) {
            cnt = 0;
        }
        else {
            cnt++;
        }
    }

    cout << count << "\n";

    return 0;
}