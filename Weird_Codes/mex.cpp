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

    Mex mex = Mex(5);

    cout << mex.get_mex() << "\n";
    mex.insert(0);
    cout << mex.get_mex() << "\n";
    mex.insert(1);
    cout << mex.get_mex() << "\n";
    mex.remove(1);
    cout << mex.get_mex() << "\n";

    return 0;
}