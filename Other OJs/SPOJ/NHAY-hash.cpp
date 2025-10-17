#include <bits/stdc++.h>

using namespace std;

string s_x = "1152921504606846989";
string s_m = "1152921504606847061";
string s_ix = "464371161577757844";

__int128_t x, mod, inv_x;

__int128_t strto128t(string &s)
{
    __int128_t n = 0;
    
    for (auto &c : s) {
        n = n * 10;
        n += (c - '0');
    }

    return n;
}

__int128_t _hash(string s)
{
    int i, n = s.size();
    __int128_t xx = x;
    __int128_t h = 0;

    for (i = 1, h = s[0]; i < n; i++) {
        h = (((h + (s[i] * xx) % mod + mod) % mod) + mod) % mod;

        xx = ((xx * x) % mod + mod) % mod;
    }

    return h;
}

void solve(int n)
{
    int i;
    string needle, haystack, needle_in_haystack;
    __int128_t xx = 1;

    cin >> needle >> haystack;

    __int128_t h_n = _hash(needle), h_h = _hash(haystack.substr(0, n));
    vector <int> pos;

    for (i = 1; i < n; i++) {
        xx = ((xx * x) % mod + mod) % mod;
    }

    if (h_n == h_h) {
        pos.push_back(1);
    }

    for (i = n; i < haystack.size(); i++) {
        h_h = ((h_h - haystack[i - n]) % mod + mod) % mod;
        h_h = ((h_h * inv_x) % mod + mod) % mod;
        h_h = ((h_h + (haystack[i] * xx) % mod) % mod + mod) % mod;

        h_h = (h_h + mod) % mod;

        if (h_n == h_h) {
            pos.push_back(i - n + 1);
        }
    }

    if (!pos.empty()) {
        for (auto &it : pos) {
            cout << it << "\n";
        }
    }
    else {
        cout << "\n";
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    x = strto128t(s_x);
    mod = strto128t(s_m);
    inv_x = strto128t(s_ix);

    int32_t n;

    while (cin >> n) {
        solve(n);
    }

    return 0;
}