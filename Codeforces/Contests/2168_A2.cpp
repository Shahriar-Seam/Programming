#include <bits/stdc++.h>

using namespace std;

#define int long long

const char separator = 'z';

char to_char(int n)
{
    return n + 'a';
}

int to_int(char c)
{
    return c - 'a';
}

void encode()
{
    int n;
    string s, t;

    cin >> n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    for (auto &it : v) {
        t = "";

        while (it) {
            t += to_char(it % 10LL);

            it /= 10LL;
        }

        reverse(t.begin(), t.end());

        while (t.size() < 10) {
            t += separator;
        }

        s += t;
    }

    cout << s << "\n";
}

void decode()
{
    string s, t;
    int pos = 0, n;
    vector <int> v;

    cin >> s;

    while (pos < s.size() - 9) {
        t = s.substr(pos, 10);
        n = 0LL;

        for (auto &c : t) {
            if (c == separator) {
                break;
            }

            n *= 10LL;

            n += to_int(c);
        }

        if (n > 0) {
            v.push_back(n);
        }

        pos += 10;
    }

    cout << v.size() << "\n";

    for (auto &it : v) {
        cout << it << " ";
    }

    cout << "\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string run;

    cin >> run;

    if (run == "first") {
        encode();
    }
    else {
        decode();
    }

    return 0;
}