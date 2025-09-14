#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;

    getline(cin, s, '\0');

    for (auto &it : s) {
        it ^= 20;
    }

    cout << s << "\n";

    return 0;
}