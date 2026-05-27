#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, i, count = 1, a, b;

    cin >> n >> m;

    vector <int> v(n), indices(n + 2, -1);

    for (i = 0; i < n; i++) {
        cin >> v[i];

        indices[v[i]] = i;
    }

    for (i = 0; i < n; i++) {
        if (v[i] > 1 && indices[v[i]] < indices[v[i] - 1]) {
            count++;
        }
    }

    while (m--) {
        cin >> a >> b;

        a--;
        b--;

        set <pair <int, int> > s;

        s.insert({indices[v[a]], indices[v[a] + 1]});
        s.insert({indices[v[a] - 1], indices[v[a]]});
        s.insert({indices[v[b]], indices[v[b] + 1]});
        s.insert({indices[v[b] - 1], indices[v[b]]});

        for (auto &[A, B] : s) {
            if (B < A) {
                count--;
            }
        }

        swap(v[a], v[b]);

        swap(indices[v[a]], indices[v[b]]);

        s.clear();

        s.insert({indices[v[a]], indices[v[a] + 1]});
        s.insert({indices[v[a] - 1], indices[v[a]]});
        s.insert({indices[v[b]], indices[v[b] + 1]});
        s.insert({indices[v[b] - 1], indices[v[b]]});

        for (auto &[A, B] : s) {
            if (B < A) {
                count++;
            }
        }

        cout << count << "\n";
    }

    return 0;
}