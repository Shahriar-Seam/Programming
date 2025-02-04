#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i, j, k, count = 0, slide = 0;
    map <int, int> mp;

    cin >> n;

    vector <int> v(n), pref(n + 1);

    for (auto &it : v) {
        cin >> it;
    }

    for (i = 0; i < n; i++) {
        pref[i + 1] = pref[i] + v[i];
    }

    for (i = 1; i <= n; i++) {
        slide = 0LL;

        for (j = 0; j < i; j++) {
            slide += v[j];
        }

        if (slide % i == 0) {
            count++;
        }

        for (j; j < n - i - 1; j++) {
            slide -= v[j];
            slide += v[j + i - 1];
        }
    }

    return 0;
}