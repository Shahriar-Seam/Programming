#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    string str;
    int z, e, r, o, n, i, m;

    cin >> t;
    cin >> str;

    z = count(str.begin(), str.end(), 'z');
    e = count(str.begin(), str.end(), 'e');
    r = count(str.begin(), str.end(), 'r');
    o = count(str.begin(), str.end(), 'o');
    n = count(str.begin(), str.end(), 'n');

    for (i = 0; i < n; i++) {
        cout << 1 << " ";
    }

    e -= n;
    o -= n;

    m = min({z, e, r, o});

    for (i = 0; i < m; i++) {
        cout << 0 << " ";
    }

    return 0;
}