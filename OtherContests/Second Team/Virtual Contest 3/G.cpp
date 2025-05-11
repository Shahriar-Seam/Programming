#include <bits/stdc++.h>

using namespace std;

#define int long long
const int inf = 1e9;

pair <int, int> recurse(vector <vector <int> > &elevations, vector <vector <bool> > &is_pass, vector <vector <int> > &cost, int i, int j, int r, int c, int n)
{
    if (j < 0) {
        return {0, 0};
    }

    if (i < 0 || elevations[i][j] == -1) {
        return {inf, inf};
    }

    if (cost[i][j] == inf) {
        auto p1 = recurse(elevations, is_pass, cost, i - 1, j - 1, r, c, n);
        auto p2 = recurse(elevations, is_pass, cost, i, j - 1, r, c, n);
        auto p3 = recurse(elevations, is_pass, cost, i + 1, j - 1, r, c, n);
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int r, c, n;
    int i, j;

    cin >> r >> c >> n;

    vector <vector <bool> > is_pass(r, vector <bool> (c, false));
    vector <vector <int> > elevations(r, vector <int> (c)), passes(r, vector <int> (c, 0)), cost(r, vector <int> (c, inf));

    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            cin >> elevations[i][j];
        }
    }

    for (i = 1; i < r - 1; i++) {
        for (j = 1; j < c - 1; j++) {
            if (elevations[i - 1][j] != -1 && elevations[i][j - 1] != -1 && elevations[i + 1][j] != -1 && elevations[i][j + 1] != -1) {
                if ((elevations[i - 1][j] > elevations[i][j] && elevations[i + 1][j] > elevations[i][j]) && (elevations[i][j - 1] < elevations[i][j] && elevations[i][j + 1] < elevations[i][j])) {
                    is_pass[i][j] = true;
                }
            }
        }
    }

    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            if (is_pass[i][j]) {
                cout << elevations[i][j] << " ";
            }
        }
    }

    cout << "\n";

    return 0;
}