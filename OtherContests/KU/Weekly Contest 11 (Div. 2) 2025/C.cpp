#include <bits/stdc++.h>

using namespace std;

struct pt {
    int x, y;

    bool operator < (const pt &p) const {
        if (x + y == p.x + p.y) {
            if (x == p.x) {
                return y < p.y;
            }
            else {
                return x < p.x;
            }
        }
        else {
            return x + y < p.x + p.y;
        }
    }

    bool operator == (const pt &p) const {
        return x == p.x && y == p.y;
    }

    bool operator != (const pt &p) const {
        return x != p.x || y != p.y;
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q, i, j, f;
    pt p;
    set <pt> s, jhamela;

    cin >> n >> q;

    while (q--) {
        cin >> p.x >> p.y;

        auto it = s.begin();

        if (s.find(p) != s.end()) {
            s.erase(s.find(p));

            if (jhamela.find(p) != jhamela.end()) {
                jhamela.erase(jhamela.find(p));
            }
        }
        else {
            s.insert(p);
            jhamela.insert(p);
        }

        f = 1;

        while (f && !jhamela.empty()) {
            it = s.find(*jhamela.begin());

            auto temp = it;

            vector <pt> v;

            v.push_back(*it);

            for (i = 0; i < 20 && it != s.begin(); i++, it--) {
                v.push_back(*it);
            }

            if (it == s.begin()) {
                v.push_back(*it);
            }

            for (i = 0, it = temp; i < 20 && it != s.end(); i++, it++) {
                v.push_back(*it);
            }

            for (i = 0; i < v.size(); i++) {
                for (j = 1; j < v.size(); j++) {
                    if (v[i] != v[j] && v[i].x != v[j].x && abs(v[i].y - v[j].y) <= 1) {
                        f = 0;
                    } 
                }
            }

            if (f) {
                jhamela.erase(jhamela.begin());
            }
        }

        if (f) {
            cout << "Yes\n";
        }
        else {
            cout << "No\n";
        }
    }

    return 0;
}