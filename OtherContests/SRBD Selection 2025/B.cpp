#include <bits/stdc++.h>

using namespace std;

bool func(string s, int n)
{
    int i;

    for (i = 1; i < n; i += 2) {
        if (s[i] == '0' && s[i - 1] == '1') {
            continue;
        }
        else {
            return false;
        }
    }

    return true;
}

int _count(string s, int n)
{
    int i, count = 0, f = 1;

    cout << s << " ";

    for (i = 0; i < n; i++) {
        if (i & 1) {
            if (s[i] == '1') {
                continue;
            }
            else {
                if (i + 1 < n && s[i + 1] == '1') {
                    s[i] = '1';
                    s[i + 1] = '0';
                    if (i + 2 < n) {
                        if (s[i + 2] == '0') {
                            s[i + 2] = '1';
                        }
                        else {
                            s[i + 2] = '0';
                        }
                    }

                    count++;
                }
                else {
                    if (i >= n - 2) {
                        // f = 0;
                    }
                    else {
                        s[i] = '1';
                        s[i + 1] = '1';
                        if (i + 2 < n) {
                            if (s[i + 2] == '0') {
                                s[i + 2] = '1';
                            }
                            else {
                                s[i + 2] = '0';
                            }
                        }

                        count++;
                    }
                }
            }
        }
        else {
            if (s[i] == '0') {
                continue;
            }
            else {
                if (i + 1 < n && s[i + 1] == '0') {
                    s[i] = '0';
                    s[i + 1] = '1';
                    if (i + 2 < n && s[i + 2] == '1') {
                        s[i + 2] = '0';
                    }

                    count++;
                }
                else {
                    if (i == 0) {
                        s[i] = '0';

                        if (i + 1 < n) {
                            if (s[i + 1] == '0') {
                                s[i + 1] = '1';
                            }
                            else {
                                s[i + 1] = '0';
                            }
                        }

                        count++;
                    }
                    else {
                        if (i >= n - 2) {
                            // f = 0;
                        }
                        else {
                            s[i] = '0';
                            if (i + 1 < n) {
                                if (s[i + 1] == '0') {
                                    s[i + 1] = '1';
                                }
                                else {
                                    s[i + 1] = '0';
                                }
                            }
                            if (i + 2 < n) {
                                if (s[i + 2] == '0') {
                                    s[i + 2] = '1';
                                }
                                else {
                                    s[i + 2] = '0';
                                }
                            }

                            count++;
                        }
                    }
                }
            }
        }
    }

    if (s.size() >= 4) {
        string t = s.substr(n - 4);

        if (t == "0000") {
            t = "0101";

            count += 3;
        }
        else if (t == "0001") {
            t = "0101";

            count += 2;
        }
        else if (t == "0010") {
            t = "0101";

            count += 1;
        }
        else if (t == "0011") {
            t = "0101";

            count += 3;
        }
        else if (t == "0100") {
            t = "0101";

            count += 3;
        }
        else if (t == "0101") {

        }
        else if (t == "0110") {
            t = "0101";

            count += 1;
        }
        else if (t == "0111") {
            t = "0101";

            count += 2;
        }
        else if (t == "1000") {
            t = "0101";

            count += 4;
        }
        else if (t == "1001") {
            t = "0101";

            count += 1;
        }
        else if (t == "1010") {
            t = "0101";

            count += 2;
        }
        else if (t == "1011") {
            t = "0101";

            count += 3;
        }
        else if (t == "1100") {
            t = "0101";

            count += 2;
        }
        else if (t == "1101") {
            t = "0101";

            count += 3;
        }
        else if (t == "1110") {
            t = "0101";

            count += 2;
        }
        else if (t == "1111") {
            t = "0101";

            count += 3;
        }

        s = s.substr(0, n - 4) + t;
    }

    for (i = 1; i < n; i++) {
        if (s[i] == s[i - 1]) {
            f = 0;
        }
    }

    cout << f << " " << count << " " << s << "\n";

    return f ? count : 1e9 + 5;
}

string flip(string s)
{
    for (auto &c : s) {
        c = (c == '0' ? '1' : '0');
    }

    return s;
}

void solve()
{
    int n, i, count = 0, f = 1;
    string s;

    cin >> n >> s;

    count = min({
        _count(s, n),
        _count(flip(s.substr(0, min(n, 2))) + s.substr(min(n, 2)), n) + 1,
        _count(flip(s.substr(0, min(n, 3))) + s.substr(min(n, 3)), n) + 1,
    });

    cout << (count == 1e9 + 5 ? -1 : count) << "\n";
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