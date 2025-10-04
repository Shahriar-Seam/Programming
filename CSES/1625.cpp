#include <bits/stdc++.h>

using namespace std;

#define valid(i, j) (min(i, j) >= 0) && (max(i, j) < 7)

const int n = 7;
vector <vector <bool> > visited(n, vector <bool> (n, false));
int cnt = 0;
string s;

bool isEmpty(int i, int j)
{
    return min(i, j) >= 0 && max(i, j) < n && !visited[i][j];
}

void recurse(string &path, int i, int j)
{
    if (!isEmpty(i - 1, j) && !isEmpty(i + 1, j) && isEmpty(i, j - 1) && isEmpty(i, j + 1)) {
        return;
    }

    if (isEmpty(i - 1, j) && isEmpty(i + 1, j) && !isEmpty(i, j - 1) && !isEmpty(i, j + 1)) {
        return;
    }

    if (i == 6 && j == 0) {
        if (path.size() == 48) {
            int k, f = 1;

            for (k = 0; k < 48; k++) {
                if (s[k] != '?' && s[k] != path[k]) {
                    f = 0;
                }
            }

            cnt += f;
        }

        return;
    }

    visited[i][j] = true;

    if (valid(i, j - 1) && !visited[i][j - 1]) {
        path += "L";

        recurse(path, i, j - 1);

        path.pop_back();
    }
    if (valid(i, j + 1) && !visited[i][j + 1]) {
        path += "R";

        recurse(path, i, j + 1);

        path.pop_back();
    }
    if (valid(i - 1, j) && !visited[i - 1][j]) {
        path += "U";

        recurse(path, i - 1, j);

        path.pop_back();
    }
    if (valid(i + 1, j) && !visited[i + 1][j]) {
        path += "D";

        recurse(path, i + 1, j);

        path.pop_back();
    }

    visited[i][j] = false;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string path;

    // cin >> s;
    s = "???????????????????????????????????????????????L";

    recurse(path, 0, 0);

    cout << cnt << "\n";

    return 0;
}