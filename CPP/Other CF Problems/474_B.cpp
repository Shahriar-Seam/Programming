#include <bits/stdc++.h>

using namespace std;

int bin_search(vector <int> &v, int key)
{
    int l = 0, r = v.size(), i;

    while (l <= r) {
        i = l + (r - l) / 2;

        if (v[i] == key) {
            return i;
        }
        else if (v[i] < key) {
            l = i + 1;
        }
        else {
            r = i - 1;
        }
    }

    return i;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i, m, temp;
    vector <int> v;

    cin >> n >> temp;

    v.push_back(temp);

    for (i = 1; i < n; i++) {
        cin >> temp;

        v.push_back(v[i - 1] + temp);
    }

    cin >> m;

    for (i = 0; i < m; i++) {
        cin >> temp;

        int index = bin_search(v, temp);

        if (temp == v[index]) {
            index++;
        }
        else if (temp < v[index]) {
            index++;
        }
        else {
            index += 2;
        }

        cout << index << "\n";
    }

    return 0;
}