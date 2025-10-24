#include <bits/stdc++.h>

using namespace std;

bool valid(int i, int j, int n, int m, vector)
{
    return min(i, j) >= 0 && i < n && j < m;
}

bool possible(vector <string> &a, vector <string> &b, int s_i, int s_j, int e_i, int e_j)
{
    if (s_i == e_i && s_j == e_j) {
        return !valid();
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, i, j;

    cin >> n >> m;

    vector <string> a(n), b(n);
    vector <pair <int, int> > start, end;

    for (auto &it : a) {
        cin >> it;
    }

    for (auto &it : b) {
        cin >> it;
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (a[i][j] == 'X') {
                start.push_back({i, j});
            }

            if (b[i][j] == 'X') {
                end.push_back({i, j});
            }
        }
    }

    sort(end.begin(), end.end());

    do {

    } while (next_permutation(end.begin(), end.end()));

    return 0;
}