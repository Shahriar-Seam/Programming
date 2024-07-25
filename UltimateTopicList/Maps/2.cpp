#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, t, code1, code2;
    string name;
    map <pair <int, int>, vector <string> > mp;

    cin >> n;

    while (n--) {
        cin >> code1 >> code2 >> name;

        mp[{code1, code2}].push_back(name);
    }

    cin >> t;

    while (t--) {
        cin >> code1 >> code2;

        cout << mp[{code1, code2}].back() << "\n";
    }

    return 0;
}