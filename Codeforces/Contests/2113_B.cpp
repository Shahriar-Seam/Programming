#include <bits/stdc++.h>

using namespace std;

#define int long long

int sq(int n)
{
    return n * n;
}

int dist(int x1, int y1, int x2, int y2)
{
    return sq(x1 - x2) + sq(y1 - y2);
}

vector <pair <int, int> > top(vector <pair <int, int> > v)
{
    int max_y = -1e12;

    vector <pair <int, int> > p;

    for (auto it : v) {
        max_y = max(max_y, it.second);
    }

    for (auto it : v) {
        if (it.second == max_y) {
            p.push_back(it);
        }
    }

    sort(p.begin(), p.end());

    return p;
}

vector <pair <int, int> > bottom(vector <pair <int, int> > v)
{
    int min_y = 1e12;

    vector <pair <int, int> > p;

    for (auto it : v) {
        min_y = min(min_y, it.second);
    }

    for (auto it : v) {
        if (it.second == min_y) {
            p.push_back(it);
        }
    }

    sort(p.begin(), p.end());

    return p;
}

vector <pair <int, int> > l_side(vector <pair <int, int> > v)
{
    int min_x = 1e12;

    vector <pair <int, int> > p;

    for (auto it : v) {
        min_x = min(min_x, it.first);
    }

    for (auto it : v) {
        if (it.first == min_x) {
            p.push_back(it);
        }
    }

    sort(p.begin(), p.end());

    return p;
}

vector <pair <int, int> > r_side(vector <pair <int, int> > v)
{
    int max_x = -1e12;

    vector <pair <int, int> > p;

    for (auto it : v) {
        max_x = max(max_x, it.first);
    }

    for (auto it : v) {
        if (it.first == max_x) {
            p.push_back(it);
        }
    }

    sort(p.begin(), p.end());

    return p;
}

void solve()
{
    int w, h, a, b;
    int x1, y1, x2, y2;
    int f = 0, g = 1;
    vector <pair <int, int> > v1, v2;
    int min_dist = LONG_LONG_MAX;
    int bleh = 0;

    cin >> w >> h >> a >> b;
    cin >> x1 >> y1 >> x2 >> y2;

    v1.push_back({x1, y1});
    v1.push_back({x1 + a, y1});
    v1.push_back({x1 + a, y1 + b});
    v1.push_back({x1, y1 + b});

    v2.push_back({x2, y2});
    v2.push_back({x2 + a, y2});
    v2.push_back({x2 + a, y2 + b});
    v2.push_back({x2, y2 + b});

    auto t1 = l_side(v1);
    auto t2 = l_side(v2);

    if (t1[0].first > t2[0].first) {
        swap(v1, v2);
    }

    for (auto it : v1) {
        for (auto &jt : v2) {
            if (dist(it.first, it.second, jt.first, jt.second) < min_dist && it.first >= 0 && it.second >= 0 && jt.first >= 0 && jt.second >= 0) {
                x1 = it.first;
                y1 = it.second;

                x2 = jt.first;
                y2 = jt.second;

                min_dist = dist(it.first, it.second, jt.first, jt.second);
            }
        }
    }

    // cout << x1 << " " << y1 << "\n";
    // cout << x2 << " " << y2 << "\n";

    if (x1 > x2) {
        swap(x1, x2);
        swap(y1, y2);
    }
    else if (x1 == x2 && y1 > y2) {
        swap(x1, x2);
        swap(y1, y2);
    }

    // 1
    t1 = top(v1);
    t2 = bottom(v2);

    if (t1[1].first > t2[0].first) {
        bleh = 1;

        if (abs(t1[0].second - t2[0].second) % b != 0) {
            g = 0;
        }
    }

    // 2
    t1 = r_side(v1);
    t2 = l_side(v2);

    if ((t1[0].first < t2[0].first) && ((t1[1].second >= t2[0].second && t1[0].second <= t2[0].second) || (t1[0].second <= t2[1].second && t1[1].second >= t2[0].second))) {
        bleh = 2;

        if (abs(t1[0].first - t2[0].first) % a != 0) {
            g = 0;
        }
    }

    // 3
    t1 = bottom(v1);
    t2 = top(v2);

    if (t1[1].first >= t2[0].first) {
        bleh = 3;
        
        if (abs(t1[0].second - t2[0].second) % b != 0) {
            g = 0;
        }
    }

    // cout << bleh << "\n";

    if (abs(y2 - y1) % b != 0) {
        f++;
    }

    if (abs(x2 - x1) % a != 0) {
        f++;
    }

    // cout << f << g << "\n";

    cout << (((f < 2) && g) ? "YES" : "NO") << "\n";
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