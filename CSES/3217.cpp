#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9 + 5;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i, j;

    cin >> n;

    vector <vector <int> > moves(n, vector <int> (n, inf));
    queue <pair <int, int> > q;
    vector <pair <int, int> > dirs = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {2, 1}, {2, -1}, {1, 2}, {1, -2}};

    q.push({0, 0});
    moves[0][0] = 0;

    while (!q.empty()) {
        auto [row, col] = q.front();
        q.pop();

        for (auto [r, c] : dirs) {
            i = row + r;
            j = col + c;

            if (min(i, j) >= 0 && max(i, j) < n && moves[i][j] == inf) {
                moves[i][j] = moves[row][col] + 1;

                q.push({i, j});
            }
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cout << moves[i][j] << " ";
        }

        cout << "\n";
    }

    return 0;
}