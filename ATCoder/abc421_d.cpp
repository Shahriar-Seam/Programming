#include <bits/stdc++.h>

using namespace std;

#define int long long

void moved_to(int r, int c, char d, int val, int &x, int &y)
{
    x = r;
    y = c;

    if (d == 'U') {
        x -= val;
    }
    else if (d == 'D') {
        x += val;
    }
    else if (d == 'R') {
        y += val;
    }
    else if (d == 'L') {
        y -= val;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int rt, ct, ra, ca, n, m, l, count = 0;

    cin >> rt >> ct >> ra >> ca;
    cin >> n >> m >> l;

    deque <pair <char, int> > t(m), a(l);

    for (auto &it : t) {
        cin >> it.first >> it.second;
    }

    for (auto &it : a) {
        cin >> it.first >> it.second;
    }

    if (rt == ra && ct == ca) {
        count--;
    }

    while (n) {
        auto T = t.front();
        auto A = a.front();

        if (T.second < A.second) {
            t.pop_front();

            a[0].second -= T.second;
        }
        else if (T.second > A.second) {
            a.pop_front();

            t[0].second -= A.second;
        }
        else {
            t.pop_front();
            a.pop_front();
        }

        int d = min(T.second, A.second);
        int x1 = rt, y1 = ct;
        int x3 = ra, y3 = ca;
        int x2, y2, x4, y4;

        n -= d;

        moved_to(x1, y1, T.first, d, x2, y2);
        moved_to(x3, y3, A.first, d, x4, y4);

        rt = x2;
        ct = y2;
        ra = x4;
        ca = y4;

        if (x1 > x2) {
            swap(x1, x2);
            swap(y1, y2);
        }

        if (x1 == x2 && y1 > y2) {
            swap(x1, x2);
            swap(y1, y2);
        }

        if (x3 > x4) {
            swap(x3, x4);
            swap(y3, y4);
        }

        if (x3 == x4 && y3 > y4) {
            swap(x3, x4);
            swap(y3, y4);
        }

        if (T.first == A.first && (x1 == x3 || y1 == y3)) {
            int temp = (min(max(y1, y2), max(y3, y4)) - max(min(y1, y2), min(y3, y4))) + (min(max(x1, x2), max(x3, x4)) - max(min(x1, x2), min(x3, x4)));

            count += temp;
        }
        else if ((T.first == 'L' && A.first == 'R') || (T.first == 'R' && A.first == 'L')) {
            if (x1 == x3) {
                if (min(max(y1, y2), max(y3, y4)) >= max(min(y1, y2), min(y3, y4))) {
                    int temp = min(max(y1, y2), max(y3, y4)) - max(min(y1, y2), min(y3, y4));

                    if (temp % 2 == 0) {
                        count++;
                    }
                }
            }
        }
        else if ((T.first == 'U' && A.first == 'D') || (T.first == 'D' && A.first == 'U')) {
            if (y1 == y3) {
                if (min(max(x1, x2), max(x3, x4)) >= max(min(x1, x2), min(x3, x4))) {
                    int temp = min(max(x1, x2), max(x3, x4)) - max(min(x1, x2), min(x3, x4));

                    if (temp % 2 == 0) {
                        count++;
                    }
                }
            }
        }
        else {
            if (x3 <= x2 && x2 <= x4 && y1 <= y4 && y4 <= y2) {
                count++;
                cout << "C " << count << "\n";
            }
            else if (x1 <= x4 && x4 <= x2 && y3 <= y2 && y2 <= y4) {
                count++;
            }
        }
    }

    cout << max(0LL, count) << "\n";

    return 0;
}