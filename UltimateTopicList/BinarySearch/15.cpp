#include <bits/stdc++.h>

using namespace std;

int n;
double min_time = 1e15;
vector <int> v_x, v_t;

bool time(double x0)
{
    double t = 0;
    int i;

    cout << x0 << ": ";

    for (i = 0; i < n; i++) {
        t += 1.0 * v_t[i] + abs(1.0 * v_x[i] - x0);

        cout << t << " ";
    }

    cout << "\n";

    if (t <= min_time) {
        min_time = t;

        return true;
    }
    else {
        return false;
    }
}

void solve()
{
    double l, r, m;
    int i;

    cin >> n;

    v_x.resize(n);
    v_t.resize(n);

    min_time = 1e15;

    for (auto &it : v_x) {
        cin >> it;
    }

    for (auto &it : v_t) {
        cin >> it;
    }

    for (i = 0, l = *min_element(v_x.begin(), v_x.end()), r = *max_element(v_x.begin(), v_x.end()); i < 30; i++) {
        m = (l + r) / 2;

        if (time(m)) {
            r = m;
        }
        else {
            l = m;
        }
    }

    cout << r << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test_cases;

    cin >> test_cases;

    while (test_cases--) {
        solve();
    }

    return 0;
}