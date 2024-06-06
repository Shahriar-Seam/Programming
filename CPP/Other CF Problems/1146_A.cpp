#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, a;
    string s;

    cin >> s;

    n = s.size();
    a = count(s.begin(), s.end(), 'a');

    if (a > n / 2) {
        cout << n;
    }
    else {
        cout << min(n, (2 * a - 1));
    }

    return 0;
}