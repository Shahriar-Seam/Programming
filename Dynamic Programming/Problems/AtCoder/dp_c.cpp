#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i;

    cin >> n;

    vector <vector <int> > v(n, vector <int> (3));

    for (auto &it : v) {
        for (i = 0; i < 3; i++) {
            cin >> it[i];
        }
    }

    for (i = 1; i < n; i++) {
        v[i][0] += max(v[i - 1][1], v[i - 1][2]);
        v[i][1] += max(v[i - 1][0], v[i - 1][2]);
        v[i][2] += max(v[i - 1][0], v[i - 1][1]);
    }
    
    cout << *max_element(v[n - 1].begin(), v[n - 1].end()) << "\n";

    return 0;
}