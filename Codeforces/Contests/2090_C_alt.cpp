#include <bits/stdc++.h>

using namespace std;

int square(int n)
{
    return n * n;
}

bool compare(pair <pair <int, int>, pair <int, int> > p1, pair <pair <int, int>, pair <int, int> > p2)
{
    int d1, d2;

    d1 = p1.first.first + p1.first.second;
    d2 = p2.first.first + p2.first.second;

    if ((p1.first.first % 3 == 2) && (p1.first.second % 3 == 2)) {
        d1++;
    }

    if ((p2.first.first % 3 == 2) && (p2.first.second % 3 == 2)) {
        d2++;
    }

    if (d1 < d2) {
        return true;
    }
    else if (d1 > d2) {
        return false;
    }
    else {
        return p1.first.first < p2.first.first;
    }
}

bool compare_s(const pair <int, int> &p1, const pair <int, int> &p2)
{
    int d1, d2;

    d1 = p1.first + p1.second;
    d2 = p2.first + p2.second;

    if (d1 < d2) {
        return true;
    }
    else if (d1 > d2) {
        return false;
    }
    else {
        return p1.first < p2.first;
    }
}

void fill(set <pair <int, int>, decltype(compare_s)*> &s1, set <int> &s2, int n, vector <pair <pair <int, int>, pair <int, int> > > &grid)
{
    int i, j;

    for (i = 0; i * i <= n + 10; i++) {
        for (j = 0; j * j <= n + 10; j++) {
            grid.push_back({{3 * i + 1, 3 * j + 1}, {i, j}});
            grid.push_back({{3 * i + 1, 3 * j + 2}, {i, j}});
            grid.push_back({{3 * i + 2, 3 * j + 1}, {i, j}});
            grid.push_back({{3 * i + 2, 3 * j + 2}, {i, j}});

            s1.insert({i, j});
        }
    }

    sort(grid.begin(), grid.end(), compare);

    for (i = 0; i < grid.size(); i++) {
        s2.insert(i);
    }
}

pair <int, int> sit(vector <vector <int> > &tables, vector <pair <pair <int, int>, pair <int, int> > > &grid, int i, set <pair <int, int>, decltype(compare_s)*> &unoccupied_table, pair <int, int> &q)
{
    pair <int, int> p;

    p = grid[i].first;
    q = grid[i].second;

    tables[q.first][q.second]++;

    unoccupied_table.erase(q);

    return p;
}

void solve()
{
    int n;

    cin >> n;

    vector <int> v(n);
    vector <vector <int> > tables(n + 10, vector <int> (n + 10, 0));
    vector <vector <bool> > bleh(n + 10, vector <bool> (n + 10, false));
    set <pair <int, int>, decltype(compare_s)*> unoccupied_table(compare_s);
    set <int> jayga_wala_cell;
    vector <pair <int, int> > cells;
    vector <pair <pair <int, int>, pair <int, int> > > grid;

    fill(unoccupied_table, jayga_wala_cell, n, grid);

    for (auto &it : v) {
        cin >> it;
    }

    for (auto it : v) {
        if (it == 1) {
            int t;

            while (true) {
                t = *jayga_wala_cell.begin();
                jayga_wala_cell.erase(jayga_wala_cell.begin());

                if (!bleh[grid[t].first.first][grid[t].first.second]) {
                    break;
                }
            }

            pair <int, int> p, q;

            p = sit(tables, grid, t, unoccupied_table, q);

            cells.push_back(p);

            bleh[p.first][p.second] = true;
        }
        else {
            auto t = *unoccupied_table.begin();
            unoccupied_table.erase(unoccupied_table.begin());

            pair <int, int> p, q;

            p = {3 * t.first + 1, 3 * t.second + 1};

            tables[t.first][t.second]++;

            cells.push_back(p);

            bleh[p.first][p.second] = true;
        }
    }

    for (auto &it : cells) {
        cout << it.first << " " << it.second << "\n";
    }

    // for (auto it : unoccupied_table) {
    //     cout << it.first << " " << it.second << "\n";
    // }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int32_t t, i;

    cin >> t;

    for (i = 1; i <= t; i++) {
        // cout << "Case " << i << ": ";

        solve();
    }

    return 0;
}