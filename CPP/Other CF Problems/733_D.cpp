#include <bits/stdc++.h>

using namespace std;

typedef struct {
    int a, b, c;
} parallelepiped;

parallelepiped transform(pair <int, int> ab, int c)
{
    parallelepiped p;
    int arr[3] = {ab.first, ab.second, c};

    sort(arr, arr + 3, greater <int> ());

    p.a = arr[0];
    p.b = arr[1];
    p.c = arr[2];

    return p;
}

parallelepiped merge(parallelepiped p1, parallelepiped p2)
{
    parallelepiped p;
    int arr[3] = {p1.a, p1.b, p1.c + p2.c};

    sort(arr, arr + 3, greater <int> ());

    p.a = arr[0];
    p.b = arr[1];
    p.c = arr[2];

    return p;
}

bool equal(parallelepiped p, vector <int> v)
{
    sort(v.begin(), v.end(), greater <int> ());

    return p.a == v[0] && p.b == v[1] && p.c == v[2];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i;
    map <pair <int, int>, vector <int>, greater <pair <int, int> > > mp;
    parallelepiped stones[2];
    int k = 0, max_min_side = 0;

    cin >> n;

    vector <vector <int> > v(n, vector <int> (3)), temp;

    for (auto &it : v) {
        for (auto &itt : it) {
            cin >> itt;
        }
    }

    temp = v;

    for (i = 0; i < n; i++) {
        sort(v[i].begin(), v[i].end(), greater <int> ());
    }

    sort(v.begin(), v.end(), greater <vector <int> > ());

    for (i = 0; i < n; i++) {
        mp[{v[i][0], v[i][1]}].push_back(v[i][2]);
    }

    for (auto it : mp) {
        if (it.second.size() > 1) {
            auto p1 = transform(it.first, it.second[0]);
            auto p2 = transform(it.first, it.second[1]);

            auto p = merge(p1, p2);

            if (p.c > max_min_side) {
                stones[0] = p1;
                stones[1] = p2;

                k = 2;

                max_min_side = p.c;
            }
        }

        if (it.second[0] > max_min_side) {
            stones[0] = transform(it.first, it.second[0]);

            max_min_side = stones[0].c;

            k = 1;
        }
    }

    cout << k << "\n";

    if (k == 1) {
        for (i = 0; i < n; i++) {
            if (equal(stones[0], temp[i])) {
                cout << i + 1;

                break;
            }
        }
    }
    else {
        for (i = 0; i < n && k > 0; i++) {
            if (equal(stones[0], temp[i]) || equal(stones[1], temp[i])) {
                cout << i + 1 << " ";

                k--;
            }
        }
    }

    cout << "\n";

    return 0;
}