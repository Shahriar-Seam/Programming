#include <bits/stdc++.h>

using namespace std;

#define int long long
const int mod = 998244353;

int binary_exponentiation(int b, int p, int m = mod)
{
    int result = 1;

    while (p > 0) {
        if (p & 1) {
            result = (result * b) % m;
        }

        b = (b * b) % m;

        p >>= 1;
    }

    return result % m;
}

bool bleh(int a, int b, int c, int d)
{
    if (a < b) {
        swap(a, b);
    }

    if (c < d) {
        swap(c, d);
    }

    if (a > c) {
        return true;
    }
    else if (a == c) {
        return b > d;
    }
    else {
        return false;
    }
}

void solve()
{
    int n, max_p = -1, max_pi = -1, max_q = -1, max_qi = -1;
    int i;
    priority_queue <pair <int, int> > pq_p, pq_q;

    cin >> n;

    vector <int> p(n), q(n), r;

    for (auto &it : p) {
        cin >> it;
    }

    for (auto &it : q) {
        cin >> it;
    }
    
    for (i = 0; i < n; i++) {
        if (p[i] > max_p) {
            max_p = p[i];
            max_pi = i;

            pq_p.push({max_p, max_pi});
        }

        if (q[i] > max_q) {
            max_q = q[i];
            max_qi = i;

            pq_q.push({max_q, max_qi});
        }

        // r.push_back(max(
        //     binary_exponentiation(2, max_p) + binary_exponentiation(2, q[i - max_pi]),
        //     binary_exponentiation(2, max_q) + binary_exponentiation(2, p[i - max_qi])
        // ) % mod);

        if (bleh(max_p, q[i - max_pi], max_q, p[i - max_qi])) {
            r.push_back((binary_exponentiation(2, max_p) + binary_exponentiation(2, q[i - max_pi])) % mod);
        }
        else {
            r.push_back((binary_exponentiation(2, max_q) + binary_exponentiation(2, p[i - max_qi])) % mod);
        }
    }

    for (auto it : r) {
        cout << it << " ";
    }

    cout << "\n";
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