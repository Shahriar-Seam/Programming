#include <bits/stdc++.h>

using namespace std;

string to_bin(long long n)
{
    string s = "";

    while (n > 0) {
        s += ('0' + n % 2);

        n /= 2;
    }

    reverse(s.begin(), s.end());

    return s;
}

long long to_int(string s)
{
    long long n = 0, i;

    for (i = s.size() - 1; i >= 0; i--) {
        if (s[i] == '1') {
            n += 1 << (s.size() - 1 - i);
        }
    }

    return n;
}

void solve()
{
    long long n, i, j = 0, previous = 0;
    string N, s1, s2;
    vector <long long> v;

    cin >> n;

    N = to_bin(n);
    s1 = N;

    while (j < 5) {
        s2 = N;

        for (i = s2.size() - 1; i >= 0; i--) {
            if (i != previous && s2[i] == '1' && s1[i] == '1') {
                s2[i] = '0';

                previous = i + 1;

                break;
            }
        }

        cout << s1 << " " << s2 << " " << previous<< "\n";

        s1 = s2;

        v.push_back(to_int(s2));

        j++;
    }

    cout << N << " " << to_int(N) << "\n";

    for (auto it : v) {
        cout << it << " ";
    }

    cout << "\n\n";
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