#include <bits/stdc++.h>

using namespace std;

#define int long long

struct query {
    int l, r, q;
};

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, i, j, temp, f = 1;

    cin >> n >> m;

    vector <query> q(m);
    vector <int> v;
    vector <vector <int> > set_bits(n + 2, vector <int> (32, 0)), unset_bits(n + 2, vector <int> (32, 0));

    for (auto &[l, r, q] : q) {
        cin >> l >> r >> q;
    }

    for (auto &[l, r, q] : q) {
        for (i = 0; i < 32; i++) {
            if (q & (1LL << i)) {
                set_bits[l][i]++;
                set_bits[r + 1][i]--;
            }
        }
    }

    for (j = 1; j < n + 2; j++) {
        for (i = 0; i < 32; i++) {
            set_bits[j][i] += set_bits[j - 1][i];

            unset_bits[j][i] += unset_bits[j - 1][i] + !(set_bits[j][i]);
        }
    }

    for (j = 1; j <= n; j++) {
        temp = 0;

        for (i = 0; i < 32; i++) {
            if (set_bits[j][i]) {
                temp |= (1LL << i);
            }
        }

        v.push_back(temp);
    }

    for (auto &[l, r, q] : q) {
        temp = 0;

        for (i = 0; i < 32; i++) {
            if (unset_bits[r][i] - unset_bits[l - 1][i] == 0) {
                temp |= (1LL << i);
            }
        }

        if (temp != q) {
            f = 0;
        }
    }

    if (f) {
        cout << "YES\n";

        for (auto &it : v) {
            cout << it << " ";
        }

        cout << "\n";
    }
    else {
        cout << "NO\n";
    }

    return 0;
}