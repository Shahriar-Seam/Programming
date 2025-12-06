#include <bits/stdc++.h>

using namespace std;

#define int long long

struct square {
    int l, r, u, d, x, y;

    square(int x, int y, int k) : x(x), y(y), l(x - k / 2), r(x + k / 2), u(y - k / 2), d(y + k / 2) {}

    bool operator < (const square &s) const {
        if (u == s.u) {
            return l < s.l;
        }
        else {
            return u < s.u;
        }
    }

    bool operator == (const square &s) {
        return x == s.x && y == s.y;
    }
};

int overlap(square p, square q)
{
    if (p == q) {
        return 0;
    }

    if (max(p.l, q.l) <= min(p.r, q.r) && max(p.u, q.u) <= min(p.d, q.d)) {
        if (p.l < q.l) {
            if (p.u < q.u) {
                return abs((p.r - q.l) * (p.d - q.u));
            }
            else {
                return abs((p.r - q.l) * (q.d - p.u));
            }
        }
        else {
            if (p.u < q.u) {
                return abs((q.r - p.l) * (p.d - q.u));
            }
            else {
                return abs((q.r - p.l) * (q.d - p.u));
            }
        }
    }
    else {
        return 0;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("squares.in", "r", stdin);
    freopen("squares.out", "w", stdout);

    int n, k, i, x, y, area = 0, count = 0, prev_area = 0, max_area = 0;
    vector <square> v;
    set <square> s, c;
    set <square> :: iterator it, prv, nxt;

    cin >> n >> k;

    for (i = 0; i < n; i++) {
        cin >> x >> y;

        v.push_back({x, y, k});
    }

    sort(v.begin(), v.end(), [&] (square &a, square &b) {
        if (a.l == b.l) {
            return a.u < b.u;
        }
        else {
            return a.l < b.l;
        }
    });

    for (auto &sq : v) {
        it = s.insert(sq).first;
        prv = (it == s.begin()) ? s.end() : prev(it);
        nxt = next(it);

        prev_area = area;

        if (prv != s.end()) {
            area = overlap(*it, *prv);

            max_area = max(max_area, area);
        }

        if (prev_area != area && area) {
            c.insert(*it);
            c.insert(*prv);

            count++;

            prev_area = area;
        }

        if (nxt != s.end()) {
            area = overlap(*it, *nxt);

            max_area = max(max_area, area);
        }

        if (prev_area != area && area) {
            c.insert(*it);
            c.insert(*nxt);

            count++;

            prev_area = area;
        }

        if (prv != s.end() && nxt != s.end()) {
            area = overlap(*prv, *nxt);

            max_area = max(max_area, area);
        }

        if (prev_area != area && area) {
            c.insert(*prv);
            c.insert(*nxt);

            count++;

            prev_area = area;
        }

        while (!s.empty()) {
            if (s.begin()->r < it->l) {
                area = overlap(*s.begin(), *it);

                max_area = max(max_area, area);

                if (prev_area != area && area) {
                    c.insert(*it);
                    c.insert(*s.begin());

                    count++;

                    prev_area = area;
                }

                nxt = s.erase(s.begin());

                prv = (nxt == s.begin()) ? s.end() : prev(nxt);

                if (prv != s.end()) {
                    area = overlap(*it, *prv);

                    max_area = max(max_area, area);
                }

                if (prev_area != area && area) {
                    c.insert(*it);
                    c.insert(*prv);

                    count++;

                    prev_area = area;
                }

                if (nxt != s.end()) {
                    area = overlap(*it, *nxt);

                    max_area = max(max_area, area);
                }

                if (prev_area != area && area) {
                    c.insert(*it);
                    c.insert(*nxt);

                    count++;

                    prev_area = area;
                }

                if (prv != s.end() && nxt != s.end()) {
                    area = overlap(*prv, *nxt);

                    max_area = max(max_area, area);
                }

                if (prev_area != area && area) {
                    c.insert(*prv);
                    c.insert(*nxt);

                    count++;

                    prev_area = area;
                }
            }
            else {
                break;
            }
        }
    }

    cout << (c.size() <= 2 ? max_area : -1) << "\n";

    return 0;
}