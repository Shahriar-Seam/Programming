#include <bits/stdc++.h>

using namespace std;

const int sz = 2e5 + 10;
vector <int> parent(sz, 0);
vector <int> _rank(sz, 0);

void init()
{
    int i;

    for (i = 0; i < sz; i++) {
        parent[i] = i;
        _rank[i] = 0;
    }
}

void make_set(int v)
{
    parent[v] = v;
    _rank[v] = 0;
}

int find_set(int v)
{
    if (parent[v] == v) {
        return v;
    }

    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b)
{
    a = find_set(a);
    b = find_set(b);

    if (a != b) {
        if (_rank[a] < _rank[b]) {
            swap(a, b);
        }

        parent[b] = a;
        _rank[a]++;
    }
}

int kruskal(int n, int m, int k)
{
    int i, u, v, c, num_edges = 0;
    int sum = 0;

    init();

    multiset <pair <int, pair <int, int> > > edges;
    vector <pair <pair <int, int>, int> > mst;

    for (i = 0; i < m; i++) {
        cin >> u >> v >> c;

        edges.insert({abs(c - k), {u, v}});
    }

    while (num_edges < n - 1) {
        auto it = *edges.begin();
        edges.erase(edges.begin());

        c = it.first;
        u = it.second.first;
        v = it.second.second;
        
        if (find_set(u) != find_set(v)) {
            cout << u << " " << v << " " << c << "\n";
            num_edges++;

            union_sets(u, v);

            if (c > k) {
                sum += c - k;
            }

            mst.push_back({{u, v}, c});
        }
    }

    return sum;
}

void solve()
{
    int n, m, k;

    cin >> n >> m >> k;

    cout << kruskal(n, m, k) << "\n";
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