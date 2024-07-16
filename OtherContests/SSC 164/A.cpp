#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s, t;
    int i, cnt = 0;

    cin >> s >> t;

    for (i = 0; i < s.size(); i++) {
        cnt += s[i] != t[i];
    }

    cout << cnt;

    return 0;
}