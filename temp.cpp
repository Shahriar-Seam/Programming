#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int mex(const set<int>& s) {
    int m = 0;
    while (s.count(m)) ++m;
    return m;
}

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n, x, y;
        cin >> n >> x >> y;
        vector<int> a(n, -1);
        vector<set<int>> friends(n);

        for (int i = 0; i < n; ++i) {
            friends[i].insert((i - 1 + n) % n);
            friends[i].insert((i + 1) % n);
        }
        friends[x - 1].insert(y - 1);
        friends[y - 1].insert(x - 1);

        for (int i = 0; i < n; ++i) {
            set<int> f_values;
            for (int f : friends[i]) {
                if (a[f] != -1) {
                    f_values.insert(a[f]);
                }
            }
            a[i] = mex(f_values);
        }

        for (int i = 0; i < n; ++i) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}