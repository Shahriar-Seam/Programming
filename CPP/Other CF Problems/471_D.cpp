#include <bits/stdc++.h>

using namespace std;

#define int long long

const int x = 1e9 + 7;
const int mod = 1e9 + 13;
const int inv_x = 833333344;

int _hash(vector <int> v)
{
    int h = 0, i, xx = 1;

    for (i = 0; i < v.size(); i++) {
        h = (h + v[i] * xx) % mod;

        xx = (xx * x) % mod;
    }

    return h;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, w, i;
    int h_a, h_b, xx = 1, count = 0, val;

    cin >> n >> w;

    vector <int> a(n), b(w), temp;

    for (auto &it : a) {
        cin >> it;
    }

    for (auto &it : b) {
        cin >> it;
    }

    if (w > n) {
        cout << 0 << "\n";

        return 0;
    }

    for (i = 0; i < w; i++) {
        val = (val + xx) % mod;

        xx = (xx * x) % mod;
    }

    xx = (xx * inv_x) % mod;

    for (i = 0; i < w; i++) {
        b[i] -= b[0];
    }

    for (i = 0; i < w; i++) {
        temp.push_back(a[i] - b[0]);
    }

    h_a = _hash(temp);
    h_b = _hash(b);

    if (h_a == h_b) {
        count++;
    }

    for (i = w; i < n; i++) {
        h_a = (h_a * inv_x) % mod;
        h_a = (h_a + (a[i] - a[i - w]) * xx) % mod;

        if (a[i - w + 1] - a[i - w] >= 0) {
            h_a = (h_a - (a[i - w + 1] - a[i - w]) * val) % mod;
        }
        else {
            h_a = (h_a - (a[i - w + 1] - a[i - w]) * val) % mod;
        }

        if (h_a == h_b) {
            count++;
        }
    }

    cout << count << "\n";

    return 0;
}