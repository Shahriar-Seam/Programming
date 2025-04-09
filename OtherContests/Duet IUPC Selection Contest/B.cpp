#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i;
    string s;

    cin >> n >> s;

    list <int> l;
    vector <list <int> :: iterator> v;

    l.push_back(0);

    v.push_back(l.begin());

    for (i = 0; i < n; i++) {
        if (s[i] == 'L') {
            v.push_back(l.insert(v.back(), i + 1));
        }
        else {
            auto it = v.back();
            it++;
            v.push_back(l.insert(it, i + 1));
        }
    }

    for (auto it : l) {
        cout << it << " ";
    }

    return 0;
}