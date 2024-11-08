#include <bits/stdc++.h>

using namespace std;

int count_bits(int n)
{
    int len = 0;

    while (n > 0) {
        len++;

        n /= 2;
    }

    return len;
}

int ulta(int n)
{
    int mask = (1 << count_bits(n)) - 1;

    return ~n & mask;
}

void test(vector <pair <int, int> > &ops)
{
    int n, i, sum = 0;

    cin >> n;

    vector <int> v(n + 1);

    for (i = 1; i <= n; i++) {
        cin >> v[i];
    }

    for (auto it : ops) {
        swap(v[it.first], v[it.second]);

        sum += it.first & it.second;
    }

    for (i = 1; i < v.size(); i++) {
        cout << v[i] << " ";
    }

    cout << "\n";

    cout << sum << "\n";

    cout << ulta(11);
}

void ultapulta(int i, int h, vector <int> &v, vector <int> &indices, vector <pair <int, int> > &ops)
{
    int temp = ulta(i);

    if (temp != h) {
        ops.push_back({temp, h});

        swap(v[temp], v[h]);
        swap(indices[v[temp]], indices[v[h]]);
    }

    if (temp != i) {
        ops.push_back({temp, i});

        swap(v[temp], v[i]);
        swap(indices[v[temp]], indices[v[i]]);
    }
}

void solve()
{
    int n, i, h;

    cin >> n;

    h = (1 << (count_bits(n) - 1));

    vector <int> v(n + 1), indices(n + 1, 0);
    vector <pair <int, int> > ops;

    for (i = 1; i <= n; i++) {
        cin >> v[i];
    }

    if (is_sorted(v.begin(), v.end())) {
        cout << 0 << "\n" << 0 << "\n";

        return;
    }

    for (i = 1; i <= n; i++) {
        indices[v[i]] = i;
    }

    if ((n & (n + 1)) == 0) {
        if (n == v[1]) {
            ops.push_back({1, n});

            swap(v[1], v[n]);
            swap(indices[v[1]], indices[v[n]]);
        }
        if (n != indices[n]) {
            if (indices[n] < h) {
                ops.push_back({indices[n], h});

                swap(v[indices[n]], v[h]);
                swap(indices[indices[n]], indices[v[h]]);
            }
            else {
                ultapulta(i, h, v, indices, ops);
            }

            if (1 != n) {
                ops.push_back({1, n});

                swap(v[1], v[n]);
                swap(indices[v[1]], indices[v[n]]);
            }
        }

        for (i = h + 1; i < n; i++) {
            if (v[i] != i) {
                if (indices[i] < h) {
                    ops.push_back({indices[i], h});

                    swap(v[indices[i]], v[h]);
                    swap(indices[v[h]], indices[v[indices[i]]]);
                }
                else if (indices[i] > h) {
                    ultapulta(i, h, v, indices, ops);
                }
            }
        }

        for (i = 1; i <= h; i++) {
            if (v[i] != i) {
                if (indices[i] < h) {
                    ops.push_back({indices[i], h});

                    swap(v[indices[i]], v[h]);
                    swap(indices[v[indices[i]]], indices[v[h]]);
                }
                else {
                    ultapulta(i, h, v, indices, ops);
                }

                if (h != i) {
                    ops.push_back({h, i});

                    swap(v[h], v[i]);
                    swap(indices[v[h]], indices[v[i]]);
                }
            }
        }
    }
    else {
        for (i = h + 1; i <= n; i++) {
            if (v[i] != i) {
                if (indices[i] < h) {
                    ops.push_back({indices[i], h});

                    swap(v[indices[i]], v[h]);
                    swap(indices[v[h]], indices[v[indices[i]]]);
                }
                else if (h < indices[i]) {
                    ultapulta(i, h, v, indices, ops);
                }

                int temp = ulta(i);

                if (temp != h) {
                    ops.push_back({temp, h});

                    swap(v[temp], v[h]);
                    swap(indices[v[temp]], indices[v[h]]);
                }

                if (temp != i) {
                    ops.push_back({temp, i});

                    swap(v[temp], v[i]);
                    swap(indices[v[temp]], indices[v[i]]);
                }
            }
        }

        for (i = 1; i <= h; i++) {
            if (v[i] != i) {
                if (indices[i] < h) {
                    ops.push_back({indices[i], h});

                    swap(v[indices[i]], v[h]);
                    swap(indices[v[indices[i]]], indices[v[h]]);
                }
                else if (indices[i] > h) {
                    ultapulta(i, h, v, indices, ops);
                }

                if (h != i) {
                    ops.push_back({h, i});

                    swap(v[h], v[i]);
                    swap(indices[v[h]], indices[v[i]]);
                }
            }
        }
    }

    if ((n & (n + 1)) == 0) {
        cout << 1 << "\n";
    }
    else {
        cout << 0 << "\n";
    }

    cout << ops.size() << "\n";

    for (auto it : ops) {
        cout << it.first << " " << it.second << "\n";
    }

    test(ops);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}