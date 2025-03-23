#include <bits/stdc++.h>

using namespace std;

int square(int n)
{
    return n * n;
}

bool compare(pair <pair <int, int>, vector <pair <int, int> > > p1, pair <pair <int, int>, vector <pair <int, int> > > p2)
{
    return square(p1.first.first) + square(p1.first.second) < square(p2.first.first) + square(p2.first.second);
}

void fill(vector <pair <pair <int, int>, vector <pair <int, int> > > > &grid, set <int> &s1, set <int> &s2, int n, vector <pair <pair <int, int>, pair <int, int> > > &tables)
{
    int i, j;

    for (i = 0; i * i <= n + 1000; i++) {
        for (j = 0; j * j <= n + 1000; j++) {
            grid.push_back({{i, j}, {{3 * i + 1, 3 * j + 1}, {3 * i + 1, 3 * j + 2}, {3 * i + 2, 3 * j + 1}, {3 * i + 2, 3 * j + 2}}});

            // tables
        }
    }

    sort(grid.begin(), grid.end(), compare);

    for (i = 0; i < grid.size(); i++) {
        s1.insert(i);
        s2.insert(i);
    }
}

pair <int, int> sit(vector <pair <pair <int, int>, vector <pair <int, int> > > > &grid, int i)
{
    pair <int, int> p;

    for (auto &it : grid[i].second) {
        if (it.first == 0 && it.second == 0) {
            continue;
        }
        else {
            p = it;

            it.first = 0;
            it.second = 0;

            break;
        }
    }

    return p;
}

bool occupied(vector <pair <pair <int, int>, vector <pair <int, int> > > > &grid, int i, set <int> s)
{
    int count = 0;

    for (auto &it : grid[i].second) {
        if (it.first == 0 && it.second == 0) {
            count++;
        }
    }

    if (count == 4) {
        s.erase(s.begin());

        return true;
    }

    return false;
}

void solve()
{
    int n;

    cin >> n;

    vector <int> v(n);
    vector <pair <pair <int, int>, vector <pair <int, int> > > > grid;
    set <int> unoccupied_table, jayga_wala_table;
    vector <pair <int, int> > cells;
    vector <pair <pair <int, int>, pair <int, int> > > tables;

    fill(grid, unoccupied_table, jayga_wala_table, n);

    for (auto &it : v) {
        cin >> it;
    }

    for (auto it : v) {
        if (it == 1) {
            auto t = *jayga_wala_table.begin();

            pair <int, int> p = sit(grid, t);

            cells.push_back(p);

            unoccupied_table.erase(t);

            occupied(grid, t, jayga_wala_table);
        }
        else {
            auto t = *unoccupied_table.begin();

            pair <int, int> p = sit(grid, t);

            cells.push_back(p);

            unoccupied_table.erase(unoccupied_table.begin());
        }
    }

    for (auto &it : cells) {
        cout << it.first << " " << it.second << "\n";
    }
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