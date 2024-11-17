#include <bits/stdc++.h>

using namespace std;

#define sz int(2e5 + 5)
vector <vector <int> > divisors(sz, vector <int> ());

void get_divisors()
{
    int i, j;

    for (i = 1; i < sz; i++) {
        for (j = i; j < sz; j += i) {
            divisors[j].push_back(i);
        }
    }
}

void solve()
{
    int k, n, m;

    cin >> k;

    vector <int> v(k);

    for (auto &it : v) {
        cin >> it;
    }

    sort(v.begin(), v.end());

    k -= 2;

    auto d = divisors[k];

    for (auto it : d) {
        if (binary_search(v.begin(), v.end(), it) && binary_search(v.begin(), v.end(), k / it)) {
            n = it;
            m = k / it;

            break;
        }
    }

    cout << n << " " << m << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    get_divisors();

    int t;

    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}