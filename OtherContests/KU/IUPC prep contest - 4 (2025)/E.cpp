#include <bits/stdc++.h>

using namespace std;

int recurse(int i, int j, int h, int w, int a, int b, vector <vector <bool> > &occupied)
{
    if (i == h) {
        return 1;
    }

    if (j == w) {
        return recurse(i + 1, 0, h, w, a, b, occupied);
    }

    if (occupied[i][j]) {
        return recurse(i, j + 1, h, w, a, b, occupied);
    }

    int num_ways = 0;

    occupied[i][j] = true;

    if (b > 0) {
        num_ways += recurse(i, j + 1, h, w, a, b - 1, occupied);
    }

    if (a > 0) {
        if (i < h - 1 && !occupied[i + 1][j]) {
            occupied[i + 1][j] = true;

            num_ways += recurse(i, j + 1, h, w, a - 1, b, occupied);

            occupied[i + 1][j] = false;
        }

        if (j < w - 1 && !occupied[i][j + 1]) {
            occupied[i][j + 1] = true;

            num_ways += recurse(i, j + 2, h, w, a - 1, b, occupied);

            occupied[i][j + 1] = false;
        }
    }

    occupied[i][j] = false;

    return num_ways;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int h, w, a, b;
    
    cin >> h >> w >> a >> b;
    
    vector <vector <bool> > occupied(h, vector <bool> (w, false));

    cout << recurse(0, 0, h, w, a, b, occupied) << "\n";

    return 0;
}