#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x, a, b;

    cin >> n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    cin >> x >> a >> b;

    v.erase(begin(v) + x - 1);
    v.erase(begin(v) + a - 1, begin(v) + b - 1);

    cout << v.size() << "\n";

    for (auto it : v) {
        cout << it << " ";
    }

    return 0;
}