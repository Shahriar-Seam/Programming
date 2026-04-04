#include <bits/stdc++.h>

using namespace std;

int trailing_zeroes(int n)
{
    int count = 0;

    while (n % 10 == 0) {
        count++;

        n /= 10;
    }

    return count;
}

int digit_length(int n)
{
    int count = 0;

    while (n > 0) {
        count++;

        n /= 10;
    }

    return count;
}

int non_zero_len(int n)
{
    return digit_length(n) - trailing_zeroes(n);
}

void solve()
{
    int n, m, len = 0, i;

    cin >> n >> m;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    sort(v.begin(), v.end(), [&] (int &a, int &b) {
        return trailing_zeroes(a) > trailing_zeroes(b);
    });

    for (i = 0; i < n; i++) {
        if (i & 1) {
            len += digit_length(v[i]);
        }
        else {
            len += non_zero_len(v[i]);
        }
    }

    if (len > m) {
        cout << "Sasha\n";
    }
    else {
        cout << "Anna\n";
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int32_t t, i;

    cin >> t;

    for (i = 1; i <= t; i++) {
        // cout << "Case " << i << ": ";

        solve();
    }

    return 0;
}