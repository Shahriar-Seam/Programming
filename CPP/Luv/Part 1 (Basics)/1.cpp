#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;
    string str;
    string s, rev_s;

    cin >> a >> b;

    cin.ignore();

    getline(cin, str);

    cin >> s;

    for (int i = s.size() - 1; i >= 0; i--) {
        rev_s.push_back(s[i]);
    }

    cout << 1LL * a * b << endl;

    cout << str << endl;

    cout << rev_s << endl;

    return 0;
}