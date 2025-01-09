#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    vector <string> v;

    cin >> s;

    sort(s.begin(), s.end());

    do {
        v.push_back(s);
    } while (next_permutation(s.begin(), s.end()));

    cout << v.size() << "\n";

    for (auto it : v) {
        cout << it << "\n";
    }

    return 0;
}