#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s1, s2;

    cin >> s1 >> s2;

    cout << s1.size() << " " << s2.size() << endl;

    cout << s1 + s2 << endl;

    s1[0] = s1[0] ^ s2[0];
    s2[0] = s1[0] ^ s2[0];
    s1[0] = s1[0] ^ s2[0];

    cout << s1 << " " << s2 << endl;

    return 0;
}