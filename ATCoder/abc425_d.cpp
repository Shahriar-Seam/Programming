#include <bits/stdc++.h>

using namespace std;

#define valid(i, j) (i >= 0 && i < h && j >= 0 && j < w)
#define count(i, j) ((valid(i, j - 1) ? v[i][j - 1] == '#' : 0) + (valid(i, j + 1) ? v[i][j + 1] == '#' : 0) + (valid(i - 1, j) ? v[i - 1][j] == '#' : 0) + (valid(i + 1, j) ? v[i + 1][j] == '#' : 0))

void recurse(int i, int j, vector <vector <bool> > &visited, vector <string> &v, int h, int w)
{
    if (!valid(i, j) || visited[i][j]) {
        return;
    }

    visited[i][j] = true;

    if (count(i, j) == 1) {
        v[i][j] = '#';
    }

    recurse(i - 1, j, visited, v, h, w);
    recurse(i + 1, j, visited, v, h, w);
    recurse(i, j - 1, visited, v, h, w);
    recurse(i, j + 1, visited, v, h, w);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int h, w, i, j, count = 0;

    cin >> h >> w;

    vector <string> v(h);
    vector <vector <bool> > visited(h, vector <bool> (w, false));

    for (auto &it : v) {
        cin >> it;
    }

    for (i = 0; i < h; i++) {
        for (j = 0; j < w; j++) {
            if (v[i][j] == '#' && !visited[i][j]) {
                recurse(i, j, visited, v, h, w);
            }
        }
    }

    for (auto &it : v) {
        cout << it << "\n";
    }

    for (i = 0; i < h; i++) {
        for (j = 0; j < w; j++) {
            count += v[i][j] == '#';
        }
    }

    cout << count << "\n";

    return 0;
}