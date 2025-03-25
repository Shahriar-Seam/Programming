#include <bits/stdc++.h>

using namespace std;

#define valid(i, j, n, m, labyrinth, visited) (i >= 0 && i < n && j >= 0 && j < m && (labyrinth[i][j] != '#') && (!visited[i][j]))

typedef struct node {
    int r, c;

    node() {
        this->r = -1;
        this->c = -1;
    }

    node (int r, int c) {
        this->r = r;
        this->c = c;
    }

} node;

string bfs(int n, int m, node root, vector <string> &labyrinth)
{
    node u, v;
    int i, j;
    queue <node> q;
    vector <vector <bool > > visited(n, vector <bool> (m, false));
    vector <vector <char> > moved(n, vector <char> (m));

    q.push(root);
    visited[root.r][root.c] = true;

    while (!q.empty()) {
        u = q.front();
        q.pop();

        i = u.r, j = u.c;

        if (labyrinth[i][j] != '#') {
            if (valid(i + 1, j, n, m, labyrinth, visited)) {
                visited[i + 1][j] = true;

                moved[i + 1][j] = 'D';

                if (labyrinth[i + 1][j] == 'B') {
                    i++;

                    break;
                }

                q.push({i + 1, j});
            }
            if (valid(i - 1, j, n, m, labyrinth, visited)) {
                visited[i - 1][j] = true;

                moved[i - 1][j] = 'U';

                if (labyrinth[i - 1][j] == 'B') {
                    i--;

                    break;
                }

                q.push({i - 1, j});
            }
            if (valid(i, j + 1, n, m, labyrinth, visited)) {
                visited[i][j + 1] = true;

                moved[i][j + 1] = 'R';

                if (labyrinth[i][j + 1] == 'B') {
                    j++;

                    break;
                }

                q.push({i, j + 1});
            }
            if (valid(i, j - 1, n, m, labyrinth, visited)) {
                visited[i][j - 1] = true;

                moved[i][j - 1] = 'L';

                if (labyrinth[i][j - 1] == 'B') {
                    j--;

                    break;
                }

                q.push({i, j - 1});
            }
        }
    }

    if ((i >= 0 && i < n && j >= 0 && j < m) && labyrinth[i][j] == 'B') {
        string s;

        while (labyrinth[i][j] != 'A') {
            s += moved[i][j];

            if (moved[i][j] == 'U') {
                i++;
            }
            else if (moved[i][j] == 'D') {
                i--;
            }
            else if (moved[i][j] == 'L') {
                j++;
            }
            else if (moved[i][j] == 'R') {
                j--;
            }
        }

        reverse(s.begin(), s.end());

        return s;
    }
    else {
        return "";
    }

}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, i, j;

    cin >> n >> m;

    vector <string> labyrinth(n);
    string path;
    node root;

    for (auto &it : labyrinth) {
        cin >> it;
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (labyrinth[i][j] == 'A') {
                root = {i, j};

                break;
            }
        }
    }

    path = bfs(n, m, root, labyrinth);

    if (path.size() > 0) {
        cout << "YES" << "\n";
        cout << path.size() << "\n";
        cout << path << "\n";
    }
    else {
        cout << "NO" << "\n";
    }

    return 0;
}