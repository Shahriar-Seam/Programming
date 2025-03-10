#include <bits/stdc++.h>

using namespace std;

typedef struct {
    char c, d;
    int a, b;

    item (char c, int a, char d, int b) {
        this->c = c;
        this->a = a;
        this->d = d;
        this->b = b;
    }

} item;

int max_val;

void recurse(int index, vector <item> &items, int l, int r, int extra) {
    if (index == items.size()) {
        max_val = max(max_val, l + r + extra);

        return;
    }

    item temp = items[index];
    int a = temp.a, b = temp.b;
    char c = temp.c, d = temp.d

    if (c == 'x' && d == 'x') {
        if (a == 3 && b == 3) {
            int left, right;

            if (l <= r) {
                if (extra >= r - l) {
                    extra -= r - l;
                    l = r;
                }
                else {
                    left += extra;
                    extra = 0;
                }
            }
            else {
                if (extra >= l - r) {
                    extra -= l - r;
                    r = l;
                }
                else {
                    right += extra;
                    extra = 0;
                }
            }

            left += extra / 2;
            extra /= 2;
            right += extra;

            recurse(index + 1, items, left, right, left * 2 + right * 2);
        }
        else if (a == 2) {
            recurse(index + 1, items, l, r + extra, (r + extra) * (b - 1) + l * (a - 1));
        }
        else {
            recurse(index + 1, items, l + extra, r + extra, (r + extra) * (b - 1) + l * (a - 1));
        }
    }
}

void solve()
{
    int n;

    cin >> n;

    vector <item> items;

    for (auto &it : items) {
        cin >> it.c >> it.a >> it.d >> it.b;
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