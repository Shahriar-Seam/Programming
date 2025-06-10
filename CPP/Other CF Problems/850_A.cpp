#include <bits/stdc++.h>

using namespace std;

struct pt {
    int a, b, c, d, e;

    pt operator - (pt p) {
        return {a - p.a, b - p.b, c - p.c, d - p.d, e - p.e};
    }
};

istream& operator >> (istream& is, pt &p) {
    return is >> p.a >> p.b >> p.c >> p.d >> p.e;
}

int dot(pt p, pt q) {
    return (p.a * q.a + p.b * q.b + p.c * q.c + p.d * q.d + p.e * q.e);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i, j, k;
    bool f;
    vector <int> indices;
    pt a, b, c;

    cin >> n;

    vector <pt> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    if (n > 100) {
        cout << "0\n";
    }
    else if (n <= 2) {
        cout << n << "\n";

        for (i = 1; i <= n; i++) {
            cout << i << "\n";
        }
    }
    else {
        for (i = 0; i < n; i++) {
            a = v[i];
            f = true;

            for (j = 0; j < n; j++) {
                if (i == j) {
                    continue;
                }

                b = v[j];

                for (k = 0; k < n; k++) {
                    if (k == j || k == i) {
                        continue;
                    }

                    c = v[k];

                    if (!((dot(b - a, c - a) == 0) || (dot(b - a, c - a) < 0))) {
                        f = false;
                    }
                }
            }

            if (f) {
                indices.push_back(i + 1);
            }
        }

        cout << indices.size() << "\n";

        for (auto it : indices) {
            cout << it << "\n";
        }
    }

    return 0;
}