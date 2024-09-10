#include <bits/stdc++.h>

using namespace std;

int count(vector <int> &v, double m, int k)
{
    int cnt = 0;

    for (auto it : v) {
        cnt += floor(it / m);
    }

    return cnt >= k;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cout << setprecision(20);

    int n, k, i, cnt;
    double l, r, m;

    cin >> n >> k;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    l = 0;
    r = 1e8;

    for (i = 0; i < 100; i++) {
        m = (l + r) / 2.0;

        if (count(v, m, k)) {
            l = m;
        }
        else {
            r = m;
        }
    }

    cout << l << "\n";

    return 0;
}