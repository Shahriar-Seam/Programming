#include <bits/stdc++.h>

using namespace std;

#define int long long

int found = 0;

void dfs(int a, int b, vector <int> &path)
{
    if (a == b) {
        cout << "YES\n";

        cout << path.size() << "\n";

        for (auto &it : path) {
            cout << it << " ";
        }

        cout << "\n";

        found = 1;
    }

    if (a > b) {
        return;
    }

    path.push_back(a * 2);
    dfs(a * 2, b, path);
    path.pop_back();

    path.push_back(a * 10 + 1);
    dfs(a * 10 + 1, b, path);
    path.pop_back();
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;
    vector <int> path;

    cin >> a >> b;

    path.push_back(a);

    dfs(a, b, path);

    if (!found) {
        cout << "NO\n";
    }

    return 0;
}