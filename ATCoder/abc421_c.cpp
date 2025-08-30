#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i, j, cnt, count = 1e18;
    string s;

    cin >> n >> s;

    deque <int> a, b;

    for (i = 0; i < 2 * n; i++) {
        if (s[i] == 'A') {
            a.push_back(i);
        }
        else {
            b.push_back(i);
        }
    }

    for (i = 0, j = 1, cnt = 0; i < n; i++, j += 2) {
        cnt += abs(b[i] - j);
    }

    count = cnt;

    for (i = 0, j = 1, cnt = 0; i < n; i++, j += 2) {
        cnt += abs(a[i] - j);
    }

    count = min(count, cnt);

    cout << count << "\n";

    return 0;
}