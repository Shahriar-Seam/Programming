#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, temp;

    cin >> n >> m;

    vector <int> v(m, 0);

    while (n--) {
        cin >> temp;

        v[temp - 1]++;
    }

    for (auto it : v) {
        cout << it << "\n";
    }

    return 0;
}