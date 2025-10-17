#include <bits/stdc++.h>

using namespace std;

string s_x = "1152921504606846989";
string s_m = "1152921504606847061";
string s_ix = "464371161577757844";

__int128_t x, mod, inv_x;

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

vector <long long> _hash(string &s, vector <long long> &p)
{
    int i, n = s.size();
    __int128_t xx = x;
    vector <long long> h(n, 0);

    for (i = 1, h[0] = s[0], p.push_back(1); i < n; i++) {
        h[i] = ((((__int128_t) h[i - 1] + (s[i] * xx) % mod + mod) % mod) + mod) % mod;

        p.push_back(xx);

        xx = ((xx * x) % mod + mod) % mod;
    }

    p.push_back(xx);

    return h;
}

int bad(string &s, vector <vector <int> > &pref, int l, int r)
{
    int i, count = 0;

    for (i = 0; i < 26; i++) {
        count += pref[r][i] - pref[l][i];
    }

    return count;
}

long long sub_hash(vector <long long> &h, int l, int r)
{
    __int128_t H;

    if (l == 0) {
        H = h[r - 1];
    }
    else {
        H = ((__int128_t(h[r - 1]) - h[l - 1]) % mod + mod) % mod;
    }

    return H;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    x = strto128t(s_x);
    mod = strto128t(s_m);
    inv_x = strto128t(s_ix);

    string s, b;
    int k, i, j, n;
    unordered_set <long long, custom_hash> hashes;
    vector <long long> h, p;
    vector <vector <int> > pref;
    __int128_t xx = 1;

    cin >> s >> b >> k;

    n = s.size();
    h = _hash(s, p);

    pref.assign(s.size() + 1, vector <int> (26, 0));

    for (i = 0; i < n; i++) {
        for (j = 0; j < 26; j++) {
            pref[i + 1][j] = pref[i][j];
        }

        if (b[s[i] - 'a'] == '0') {
            pref[i + 1][s[i] - 'a']++;
        }
    }

    for (i = 0; i < s.size(); i++) {
        for (j = i + 1; j <= s.size(); j++) {
            if (bad(s, pref, i, j) <= k) {
                hashes.insert(((__int128_t(p[n - i]) * sub_hash(h, i, j)) % mod + mod) % mod);
            }
        }
    }

    cout << hashes.size() << "\n";

    return 0;
}