#include <bits/stdc++.h>

using namespace std;

#define int long long

const int sz = 5005;
int M;
vector <vector <int> > C(sz, vector <int> (sz, 1));

void nCr()
{
    int i, j;

    for (i = 2; i < sz; i++) {
        for (j = 1; j < i; j++) {
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % M;
        }
    }
}

void solve()
{
    int n, sum = 0, count = 1;

    cin >> n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;

        sum += it;
    }

    for (auto &it : v) {
        count = (count * C[sum][it]) % M;

        sum -= it;
    }

    cout << count << "\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int32_t t, i;
    
    cin >> t >> M;

    nCr();

    for (i = 1; i <= t; i++) {
        // cout << "Case " << i << ": ";

        solve();
    }

    return 0;
}