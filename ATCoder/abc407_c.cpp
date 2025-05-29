#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    int sum = 0, i;

    cin >> s;

    for (i = s.size() - 1; i >= 0; i--) {
        sum += ((((s[i] - '0') - sum) % 10) + 10) % 10;
    }

    cout << sum + s.size() << "\n";

    return 0;
}