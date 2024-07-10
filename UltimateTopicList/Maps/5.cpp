#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    string s;
    map <string, int> mp;

    cin >> n;

    while (n--) {
        cin >> s;

        mp[s]++;

        cout << (mp[s] > 1 ? "YES" : "NO") << "\n";
    }

    return 0;
}