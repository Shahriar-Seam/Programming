#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x, cnt = 0, i, l, r;

    cin >> n >> x;

    vector <long long> v(n), prefix(n + 1);

    for (auto &it : v) {
        cin >> it;
    }

    for (i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + v[i];
    }

    for (l = 0, r = 1; r <= n; ) {
        if (prefix[r] - prefix[l] == x) {
            cnt++;
            l++;
            r++;
        }
        else if (prefix[r] - prefix[l] > x) {
            l++;
        }
        else {
            r++;
        }
    }

    cout << cnt;

    return 0;
}