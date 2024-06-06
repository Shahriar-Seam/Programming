#include <bits/stdc++.h>

using namespace std;

int binarySearch(vector <int> &v, int key)
{
    int l = 0, r = v.size() - 1, mid;

    while (l <= r) {
        mid = (l + r) / 2;

        if (v[mid] == key) {
            return mid;
        }
        else if (v[mid] > key) {
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }

    return -1;
}

void solve()
{
    int n, m, i, temp, f = 1, index, meh;
    vector <int> a, b, d, d_copy;
    vector <pair <int, int> > v;
    map <int, int> mp;

    cin >> n;

    for (i = 0; i < n; i++) {
        cin >> temp;

        a.push_back(temp);
    }

    for (i = 0; i < n; i++) {
        cin >> temp;

        b.push_back(temp);
    }

    cin >> m;

    for (i = 0; i < m; i++) {
        cin >> temp;

        d.push_back(temp);
    }

    d_copy = d;

    sort(d.begin(), d.end());

    for (auto it : d) {
        v.push_back(make_pair(it, -1));
    }

    for (i = 0; i < n; i++) {
        index = binarySearch(d, b[i]);

        if (index != -1) {
            if (v[index].second == -1) {
                v[index].second = i;
            }
            else {
                temp = index;
                meh = v[index].first;
                f = 1;

                while (temp < n && v[temp].first == meh) {
                    if (v[index].second == -1) {
                        v[index].second = i;

                        f = 0;

                        break;
                    }

                    temp++;
                }

                if (f == 0) {
                    temp = index;
                    meh = v[index].first;
                    f = 1;

                    while (temp < n && v[temp].first == meh) {
                        if (v[index].second == -1) {
                            v[index].second = i;

                            f = 0;

                            break;
                        }

                        temp--;
                    }
                }
            }
        }
    }

    for (i = 0; i < m; i++) {
        if (v[i].second != -1) {
            a[v[i].second] = v[i].first;
        }
    }
    
    cout << (a == b ? "YES\n" : "NO\n");
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}