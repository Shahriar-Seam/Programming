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

int _hash(string s)
{
    int h = 0, i, xx = 1;

    for (i = 0; i < s.size(); i++) {
        h = (h + s[i] * xx) % mod;

        xx = (xx * x) % mod;
    }

    return h;
}