#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("words.txt", "r", stdin);

    string s;

    cin >> s;

    s = regex_replace(s, regex("\",\""), "\n");
    s.pop_back();
    s.erase(s.begin());

    freopen("words.txt", "w", stdout);

    cout << s;

    return 0;
}