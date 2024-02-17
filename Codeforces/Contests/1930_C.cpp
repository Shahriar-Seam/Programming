#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n, i, temp;
    map <int, vector <int> > m;
    set <int> s;
    vector <int> v;

    cin >> t;

    while (t--) {
        cin >> n;

        for (i = 0; i < n; i++) {
            cin >> temp;

            m[temp + i + 1].push_back(i);
        }

        for (auto it = s.rbegin(); it != s.rend(); it++) {
            cout << *it << " ";
        }

        cout << "\n";

        m.clear();
        s.clear();
    }

    return 0;
}