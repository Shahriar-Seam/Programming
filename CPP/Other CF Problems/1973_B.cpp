#include <bits/stdc++.h>

using namespace std;

void pops(vector <int> &set_bits, int n)
{
    int i;

    for (i = 0; i < 25; i++) {
        if (n & (1 << i)) {
            set_bits[i]++;
        }
    }
}

void unset(vector <int> &set_bits, int n)
{
    int i;

    for (i = 0; i < 25; i++) {
        if (n & (1 << i)) {
            set_bits[i]--;
        }
    }
}

int to_num(vector <int> &set_bits)
{
    int num = 0, i;

    for (i = 0; i < 25; i++) {
        if (set_bits[i] > 0) {
            num |= (1 << i);
        }
    }

    return num;
}

bool possible(vector <int> &v, int k)
{
    vector <int> set_bits(25, 0);
    int i, j, lonely = 0;

    for (i = 0; i < k; i++) {
        pops(set_bits, v[i]);

        lonely |= v[i];
    }

    for (i = k; i < v.size(); i++) {
        unset(set_bits, v[i - k]);
        pops(set_bits, v[i]);
        
        if (to_num(set_bits) != lonely) {
            return false;
        }
    }

    return true;
}

void solve()
{
    int n;

    cin >> n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    int l = 1, r = n, mid, k = n;

    while (l <= r) {
        mid = (l + r) / 2;

        if (possible(v, mid)) {
            k = mid;
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }

    cout << k << "\n";
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