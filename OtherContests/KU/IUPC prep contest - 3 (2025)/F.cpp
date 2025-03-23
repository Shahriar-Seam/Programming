#include <bits/stdc++.h>

using namespace std;

#define int long long

const int sz = 2e5 + 10;
vector <int> parent(sz, 0);
vector <int> _rank(sz, 0);
vector <pair <int, pair <int, int> > > edges;
map <pair <int, int>, int> mp;

int bin_search(int k)
{
    int l = 0, r = edges.size() - 1, m, index = r;

    while (l <= r) {
        m = (l + r) / 2;

        if (edges[m].first >= k) {
            index = m;
            r = m - 1;
        }
        else {
            l = m + 1;
        }
    }

    return index;
}

void init(int n)
{
    int i;

    for (i = 0; i <= n; i++) {
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
    int u, v, c, num_edges = 0;
    int sum = 0, index, i = 0;

    init(n);

    index = bin_search(k);

    if(edges[index].first >= k) {
        sum += edges[index].first - k;
    }
    else {
        return 4e18;
    }

    union_sets(edges[index].second.first, edges[index].second.second);

    num_edges++;

    while (num_edges <= n - 2) {
        if (i == index) {
            i++;
            continue;
        }

        auto it = edges[i++];

        c = it.first;
        u = it.second.first;
        v = it.second.second;
        
        if (find_set(u) != find_set(v)) {
            num_edges++;

            union_sets(u, v);

            if (c > k) {
                sum += c - k;
            }
        }
    }

    return sum;
}

int kruskal2(int n, int m, int k)
{
    int u, v, c, num_edges = 0;
    int sum = 0, index, i = 0;

    init(n);

    index = bin_search(k);

    if (edges[index].first > k) {
        if (index > 0) {
            index--;
        }
        else {
            return 4e18;
        }
    }

    union_sets(edges[index].second.first, edges[index].second.second);
    num_edges++;

    while (i < edges.size() && num_edges <= n - 2) {
        if (i == index) {
            i++;
            continue;
        }

        auto it = edges[i++];

        c = it.first;
        u = it.second.first;
        v = it.second.second;
        
        if (find_set(u) != find_set(v)) {
            num_edges++;

            union_sets(u, v);

            if (c > k) {
                sum += c - k;
            } 
        }
    }

    if (sum == 0) {
        sum = k - edges[index].first;
    }

    return sum;
}

void solve()
{
    int n, m, k, i;
    int u, v, c;

    edges.clear();
    mp.clear();

    cin >> n >> m >> k;
    
    for (i = 0; i < m; i++) {
        cin >> u >> v >> c;

        edges.push_back({c, {u, v}});
        mp[{u, v}] = c;
    }

    sort(edges.begin(), edges.end());

    // cout << kruskal(n, m, k) << "\n";
    cout << min(kruskal(n, m, k), kruskal2(n, m, k)) << "\n";
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