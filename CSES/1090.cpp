#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x, i, j;

    cin >> n >> x;

    vector <int> v(n), g;

    for (auto &it : v) {
        cin >> it;
    }

    sort(v.begin(), v.end(), greater <int> ());

    for (i = 0, j = n - 1; i <= j; ) {
        g.push_back(v[i]);
        i++;

        if (g.back() + v[i] <= x) {
            g[g.size() - 1] += v[i];
            i++;
        }
        else if (g.back() + v[j] <= x) {
            g[g.size() - 1] += v[j];
            j--;
        }
    }

    cout << g.size() << "\n";

    return 0;
}