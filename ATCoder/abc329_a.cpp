#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    int i, l;

    cin >> s;

    l = s.length();

    for (i = 0; i < l; i++) {
        cout << s[i] << " ";
    }

    return 0;
}