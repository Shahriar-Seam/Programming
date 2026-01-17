#include <bits/stdc++.h>

using namespace std;

#define int long long

const int sz = 1e7 + 5;
int divisors[sz] = {};
vector <pair <int, int> > nums;

void fill_divisors()
{
    int i, j;

    for (i = 1; i < sz; i++) {
        for (j = i * 2; j < sz; j += i) {
            divisors[j] += i;
        }
    }

    for (i = 1; i < sz; i++) {
        if (divisors[i] < sz && i == divisors[divisors[i]] && i != divisors[i] && i < divisors[i]) {
            nums.push_back({i, divisors[i]});
        }
    }
}

void solve()
{
    int a, b;

    cin >> a >> b;

    auto it = lower_bound(nums.begin(), nums.end(), make_pair(a, 0LL));

    while (it < nums.end()) {
        if (it->second <= b) {
            cout << it->first << " " << it->second << "\n";
        }

        it++;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    fill_divisors();

    int32_t t, i;

    cin >> t;

    for (i = 1; i <= t; i++) {
        cout << "Case " << i << ":\n";

        solve();
    }

    return 0;
}