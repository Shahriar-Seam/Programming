#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str;

    cin >> str;

    int i, l = str.size();
    for (i = 0; i < l / 2; i++) {
        str[i] = str[i] ^ str[l - i - 1];
        str[l - i - 1] = str[i] ^ str[l - i - 1];
        str[i] = str[i] ^ str[l - i - 1];
    }

    cout << str << endl;

    return 0;
}