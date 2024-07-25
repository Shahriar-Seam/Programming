#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    int i, balance = 0;
    vector <tuple <int, int, char> > v;

    cin >> s;

    for (i = 0; s[i] != 0; i++) {
        v.push_back(make_tuple(balance, -i, s[i]));

        balance += s[i] == '(' ? 1 : -1;
    }

    sort(begin(v), end(v));

    for (i = 0; i < v.size(); i++) {
        cout << get<2>(v[i]);
    }

    return 0;
}