#include <bits/stdc++.h>

using namespace std;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    template <typename T>
    size_t operator()(const T& x) const {
        return hash_combine(x);
    }

private:
    static const uint64_t FIXED_RANDOM;

    // Arithmetic types (int, long long, etc.)
    template <typename T>
    static typename enable_if<is_integral<T>::value, size_t>::type
    hash_combine(const T& x) {
        return splitmix64(x + FIXED_RANDOM);
    }

    // string specialization
    static size_t hash_combine(const string& s) {
        size_t h = 0;
        for (char c : s) {
            h = h * 31 + c;
        }
        return splitmix64(h + FIXED_RANDOM);
    }

    // pair
    template <typename T1, typename T2>
    static size_t hash_combine(const pair<T1, T2>& p) {
        size_t h1 = custom_hash{}(p.first);
        size_t h2 = custom_hash{}(p.second);
        return h1 ^ (h2 << 1);
    }

    // tuple
    template <typename Tuple, size_t Index = 0>
    static typename enable_if<Index == tuple_size<Tuple>::value, size_t>::type
    hash_tuple(const Tuple&) {
        return 0;
    }

    template <typename Tuple, size_t Index = 0>
    static typename enable_if<Index < tuple_size<Tuple>::value, size_t>::type
    hash_tuple(const Tuple& t) {
        size_t h1 = custom_hash{}(get<Index>(t));
        size_t h2 = hash_tuple<Tuple, Index + 1>(t);
        return h1 ^ (h2 << 1);
    }

    template <typename... Ts>
    static size_t hash_combine(const tuple<Ts...>& t) {
        return hash_tuple(t);
    }

    // Iterable containers (e.g., vector, set, unordered_set)
    template <typename T>
    static typename enable_if<!is_integral<T>::value &&
                              !is_same<T, string>::value &&
                              !is_same<T, tuple<typename T::value_type>>::value &&
                              !is_same<T, pair<typename T::first_type, typename T::second_type>>::value,
                              size_t>::type
    hash_combine(const T& container) {
        size_t h = 0;
        for (const auto& x : container) {
            h ^= custom_hash{}(x) + 0x9e3779b9 + (h << 6) + (h >> 2);
        }
        return h;
    }
};

const uint64_t custom_hash::FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();

int dijkstra(int n, vector <vector <pair <int, int> > > &adj_list) {
    priority_queue <pair <int, int>, vector <pair <int, int> >, greater <> > pq;
    vector <unordered_set <int, custom_hash> > visited(n + 1);
    int _or, u, v, w, new_or;

    pq.emplace(0, 1);

    while (!pq.empty()) {
        auto it = pq.top();

        _or = it.first;
        u = it.second;

        pq.pop();

        if (u == n) {
            return _or;
        }

        if (visited[u].find(_or) != visited[u].end()) {
            continue;
        }

        visited[u].insert(_or);

        for (auto &it : adj_list[u]) {
            new_or = (_or | it.second);

            if (visited[it.first].find(new_or) == visited[it.first].end()) {
                pq.emplace(new_or, it.first);
            }
        }
    }

    return 0;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, u, v, w, i;

    cin >> n >> m;

    vector <vector <pair <int, int> > > adj_list(n + 1);
    vector <int> d, p, path;

    for (i = 0; i < m; i++) {
        cin >> u >> v >> w;

        adj_list[u].emplace_back(v, w);
        adj_list[v].emplace_back(u, w);
    }

    cout << dijkstra(n, adj_list) << "\n";

    return 0;
}