#include <bits/stdc++.h>

using namespace std;

struct rect {
    int r1, c1, r2, c2;

    bool operator == (rect R) {
        return r1 == R.r1 && r2 == R.r2 && c1 == R.c1 && c2 == R.c2;
    }

    bool operator != (rect R) {
        return !(*this == R);
    }

    bool in(rect R) {
        return r1 <= R.r1 && R.r2 <= r2 && c1 <= R.c1 && R.c2 <= c2;
    }
};

struct coord {
    int r, c;

    coord operator + (coord C) {
        return {r + C.r, c + C.c};
    }
};

vector <coord> direction = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int n;

bool inside(coord C, rect R)
{
    return C.r >= R.r1 && C.r <= R.r2 && C.c >= R.c1 && C.c <= R.c2;
}

void dfs(vector <string> &v, char &parent, vector <vector <bool> > &visited, coord C, rect R)
{
    if (inside(C, R) && !visited[C.r][C.c] && v[C.r][C.c] == parent) {
        visited[C.r][C.c] = true;

        for (auto &d : direction) {
            dfs(v, parent, visited, C + d, R);
        }
    }
}

bool valid_rect(rect R, vector <string> &v)
{
    map <char, int> color;
    vector <vector <bool> > visited(n, vector <bool> (n, false));
    int r, c;

    for (r = R.r1; r <= R.r2; r++) {
        for (c = R.c1; c <= R.c2; c++) {
            if (!visited[r][c]) {
                color[v[r][c]]++;

                dfs(v, v[r][c], visited, {r, c}, R);
            }
        }
    }

    if (color.size() != 2) {
        return false;
    }

    auto a = *color.begin();
    color.erase(color.begin());

    auto b = *color.begin();
    color.erase(color.begin());

    if ((a.second == 1 && b.second > 1) || a.second > 1 && b.second == 1) {
        return true;
    }
    else {
        return false;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("where.in", "r", stdin);
    freopen("where.out", "w", stdout);

    int r1, c1, r2, c2, count = 0, f;

    cin >> n;

    vector <string> v(n);
    vector <rect> pcls;

    for (auto &it : v) {
        cin >> it;
    }

    for (r1 = 0; r1 < n; r1++) {
        for (c1 = 0; c1 < n; c1++) {
            for (r2 = r1; r2 < n; r2++) {
                for (c2 = c1; c2 < n; c2++) {
                    if (valid_rect({r1, c1, r2, c2}, v)) {
                        pcls.push_back({r1, c1, r2, c2});
                    }
                }
            }
        }
    }

    for (auto &it : pcls) {
        f = 1;

        for (auto &jt : pcls) {
            if (it != jt && jt.in(it)) {
                f = 0;
            }
        }

        count += f;
    }

    cout << count << "\n";

    return 0;
}