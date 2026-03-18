#include <bits/stdc++.h>

using namespace std;

using node = pair <int, int>;
#define x first
#define y second

vector <int> dx = {0, 0, 1, 1, 1, -1, -1, -1};
vector <int> dy = {-1, 1, -1, 0, 1, -1, 0, 1};


int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, r, a, b, i, j;
    node U, V, u, v;
    map <pair <int, int>, int> allowed, visited, level;
    deque <pair <int, int> > dq;

    cin >> U.x >> U.y >> V.x >> V.y;

    cin >> n;

    for (i = 0; i < n; i++) {
        cin >> r >> a >> b;

        for (j = a; j <= b; j++) {
            allowed[{r, j}] = 1;
        }
    }

    dq.push_back(U);
    visited[U] = 1;
    level[U] = 0;

    while (!dq.empty()) {
        u = dq.front();
        dq.pop_front();

        if (u == V) {
            break;
        }

        for (i = 0; i < 8; i++) {
            v = {u.x + dx[i], u.y + dy[i]};

            if (allowed[v] && !visited[v]) {
                visited[v] = 1;
                level[v] = level[u] + 1;

                dq.push_back(v);
            }
        }
    }

    if (level[V] == 0) {
        cout << "-1\n";
    }
    else {
        cout << level[V] << "\n";
    }

    return 0;
}