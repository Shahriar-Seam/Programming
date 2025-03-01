#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    string s;

    cin >> n;

    while (n > 0) {
        s.push_back('a' + ((n % 26) == 0 ? 25 : (n % 26) - 1));

        n -= 1;
        n /= 26;
    }

    reverse(s.begin(), s.end());

    cout << s << "\n";

    return 0;
}