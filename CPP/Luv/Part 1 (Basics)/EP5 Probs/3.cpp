#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str, str1;

    cin >> str;
    str1 = str;

    int i, l = str.size();

    for (i = 0; i < l / 2; i++) {
        str[i] = str[i] ^ str[l - i - 1];
        str[l - i - 1] = str[i] ^ str[l - i - 1];
        str[i] = str[i] ^ str[l - i - 1];
    }

    str1 == str ? cout << "YES\n" : cout << "NO\n";

    return 0;
}