#include <bits/stdc++.h>

using namespace std;

struct Mex {
    int sz;
    vector <int> freq;
    set <int> available;

    Mex(int n) {
        sz = n;

        freq.assign(sz, 0);

        for (int i = 0; i <= sz; i++) {
            available.insert(i);
        }
    }

    bool valid(int n) {
        return n < sz;
    }

    void insert(int n) {
        if (valid(n)) {
            freq[n]++;

            if (freq[n] == 1) {
                available.erase(n);
            }
        }
    }

    void remove(int n) {
        if (valid(n)) {
            freq[n]--;

            if (freq[n] == 0) {
                available.insert(n);
            }
        }
    }

    int get_mex() {
        return *available.begin();
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, i;

    cin >> n >> k;

    vector <int> v(n);
    Mex mex(k);

    for (auto &it : v) {
        cin >> it;
    }

    for (i = 0; i < k; i++) {
        mex.insert(v[i]);
    }

    cout << mex.get_mex() << " ";

    for (i = k; i < n; i++) {
        mex.insert(v[i]);
        mex.remove(v[i - k]);

        cout << mex.get_mex() << " ";
    }

    cout << "\n";

    return 0;
}