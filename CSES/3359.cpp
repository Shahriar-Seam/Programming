#include <bits/stdc++.h>

using namespace std;

struct pt {
    int r, c;

    pt() : r(0), c(0) {}

    pt(int r, int c) : r(r), c(c) {}

    pt operator + (pt p) const {
        return pt(r + p.r, c + p.c);
    }

    bool operator < (const pt p) const {
        if (r == p.r) {
            return c < p.c;
        }
        else {
            return r < p.r;
        }
    }
};

bool valid(pt p, int n)
{
    return max(p.r, p.c) < n;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i;
    string s;
    char mn;
    vector <pt> st;

    cin >> n;

    vector <string> v(n);
    vector <vector <bool> > visited(n, vector <bool> (n, 0));

    for (auto &it : v) {
        cin >> it;
    }

    s = v[0][0];
    st.push_back(pt(0, 0));
    visited[0][0] = true;

    for (i = 2; i < 2 * n; i++) {
        mn = 'Z' + 1;

        vector <pt> temp;

        for (auto &it : st) {
            pt p = it + pt(0, 1);
            pt q = it + pt(1, 0);

            if (valid(p, n)) {
                mn = min(mn, v[p.r][p.c]);
            }
            if (valid(q, n)) {
                mn = min(mn, v[q.r][q.c]);
            }
        }

        s += mn;

        for (auto &it : st) {
            pt p = it + pt(0, 1);
            pt q = it + pt(1, 0);

            if (valid(p, n) && v[p.r][p.c] == mn && !visited[p.r][p.c]) {
                visited[p.r][p.c] = true;
                temp.push_back(p);
            }
            
            if (valid(q, n) && v[q.r][q.c] == mn && !visited[q.r][q.c]) {
                visited[q.r][q.c] = true;
                temp.push_back(q);
            }
        }

        st = move(temp);
    }

    cout << s << "\n";

    return 0;
}