#include <bits/stdc++.h>

using namespace std;

struct pt {
    int r, c;
    char d;

    pt() : r(-1), c(-1), d('0') {}

    pt(int r, int c) : r(r), c(c), d('0') {}

    pt(int r, int c, char d) : r(r), c(c), d(d) {}

    bool valid(int n, int m, vector <string> &v) const {
        return min(r, c) >= 0 && r < n && c < m && v[r][c] != '#';
    }

    pt operator + (pt p) {
        pt q(r + p.r, c + p.c);

        if (p.r == 1) {
            q.d = 'D';
        }
        else if (p.r == -1) {
            q.d = 'U';
        }
        else if (p.c == 1) {
            q.d = 'R';
        }
        else if (p.c == -1) {
            q.d = 'L';
        }

        return q;
    }

    bool operator == (pt p) {
        return r == p.r && c == p.c;
    }

    bool operator != (pt p) {
        return !(*this == p);
    }
};

vector <pt> diff = {pt(1, 0), pt(-1, 0), pt(0, 1), pt(0, -1)};

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, i, j, reached = 0, inf = 1e9 + 5;
    pt start, end;
    deque <pt> dq;

    cin >> n >> m;

    vector <string> v(n);
    vector <vector <bool> > visited(n, vector <bool> (m, false));
    vector <vector <int> > cost(n, vector <int> (m, inf));
    vector <vector <int> > cost2(n, vector <int> (m, inf));
    vector <vector <pt> > parent(n, vector <pt> (m));

    for (auto &it : v) {
        cin >> it;
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (v[i][j] == 'M') {
                dq.push_back(pt(i, j));
                cost[i][j] = 0;
                visited[i][j] = true;
            }
            else if (v[i][j] == 'A') {
                start = pt(i, j);
                cost2[i][j] = 0;
            }
        }
    }

    while (!dq.empty()) {
        auto p = dq.front();
        dq.pop_front();

        for (auto &d : diff) {
            auto q = p + d;

            if (q.valid(n, m, v) && !visited[q.r][q.c]) {
                cost[q.r][q.c] = cost[p.r][p.c] + 1;

                visited[q.r][q.c] = true;

                dq.push_back(q);
            }
        }
    }

    visited.assign(n, vector <bool> (m, false));
    
    dq.push_back(start);
    visited[start.r][start.c] = true;

    while (!dq.empty()) {
        auto p = dq.front();
        dq.pop_front();

        if (reached || p.r == 0 || p.r == n - 1 || p.c == 0 || p.c == m - 1) {
            if (reached == 0) {
                end = p;
                reached = 1;
            }

            break;
        }

        for (auto &d : diff) {
            auto q = p + d;

            if (q.valid(n, m, v) && !visited[q.r][q.c] && cost2[p.r][p.c] + 1 < cost[q.r][q.c]) {
                cost2[q.r][q.c] = cost2[p.r][p.c] + 1;

                visited[q.r][q.c] = true;

                parent[q.r][q.c] = p;

                dq.push_back(q);
            }
        }
    }

    if (reached) {
        string s;

        auto p = end;

        while (p != start) {
            s += p.d;

            p = parent[p.r][p.c];
        }

        reverse(s.begin(), s.end());

        cout << "YES\n" << s.size() << "\n" << s << "\n";
    }
    else {
        cout << "NO\n";
    }

    return 0;
}