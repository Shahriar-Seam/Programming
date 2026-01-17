#include <bits/stdc++.h>

using namespace std;

#define int long long

struct ordered_set {
    vector <pair <int, int> > v;

    ordered_set() {}

    void insert(pair <int, int> p) {
        v.emplace_back(p);
    }

    void sort() {
        std::sort(v.begin(), v.end());
    }

    int order_of_key(pair <int, int> p) {
        return lower_bound(v.begin(), v.end(), p) - v.begin();
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q, temp, x, y, l, r, m, val, ord;
    ordered_set os;

    cin >> n >> q;

    while (n--) {
        cin >> temp;

        os.insert({temp, 0});
    }

    os.sort();
    
    while (q--) {
        cin >> x >> y;
        
        ord = os.order_of_key({x, -1});

        l = x;
        r = 10e15;

        while (l < r) {
            m = (l + r) / 2;

            if (m - x - (os.order_of_key({m, 1}) - ord - 1) >= y) {
                r = m - 1;

                val = m;
            }
            else {
                l = m + 1;
            }
        }

        temp = val;

        for (m = temp; m >= max(x, temp - 50); m--) {
            if (m - x - (os.order_of_key({m, 1}) - ord - 1) >= y) {
                val = m;
            }
            else {
                break;
            }
        }

        cout << val << "\n";
    }

    return 0;
}