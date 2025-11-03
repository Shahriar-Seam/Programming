#include <bits/stdc++.h>

using namespace std;

#define int long long

string s_x = "1152921504606846989";
string s_m = "1152921504606847061";
string s_ix = "464371161577757844";

__int128_t x, mod, inv_x;
vector <__int128_t> p_x;

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

__int128_t strto128t(string &s)
{
    __int128_t n = 0;
    
    for (auto &c : s) {
        n = n * 10;
        n += (c - '0');
    }

    return n;
}

vector <int> _hash(string &s)
{
    int i;
    __int128_t xx = 1;
    vector <int> h(s.size(), 0);

    p_x.assign(s.size(), 0);

    for (i = 0; i < s.size(); i++) {
        h[i] = ((((i > 0LL ? h[i - 1] : 0LL) + (s[i] * xx)) % mod + mod) % mod);

        p_x[i] = xx;

        xx = (((xx * x) % mod + mod) % mod);
    }

    return h;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    x = strto128t(s_x);
    mod = strto128t(s_m);
    inv_x = strto128t(s_ix);

    int k, n, i, j, f = 1;
    string s;
    vector <int> h;
    unordered_set <int, custom_hash> us;

    cin >> k >> n;

    vector <string> v(k);

    for (auto &it : v) {
        cin >> it;
    }

    s = v[0];

    h = _hash(s);

    us.insert(h.back());

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (s[i] != s[j]) {
                __int128_t H = h.back();

                H = H - (((s[i] * p_x[i]) % mod + mod) % mod) - (((s[j] * p_x[j]) % mod + mod) % mod);

                H = H + (((s[i] * p_x[j]) % mod + mod) % mod) + (((s[j] * p_x[i]) % mod + mod) % mod);

                H = ((H % mod) + mod) % mod;

                us.insert((long long) H);

                auto t = s;

                swap(t[i], t[j]);
            }
        }
    }

    cout << us.size() << "\n";

    for (auto &it : v) {
        if (us.find(_hash(it).back()) == us.end()) {
            cout << it << "\n";

            f = 0;
        }
    }

    cout << (f ? s : "-1") << "\n";

    return 0;
}