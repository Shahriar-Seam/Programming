#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i, temp;

    cin >> n;

    vector <int> v1, v2(n, 0);

    for (i = 0; i < n; i++) {
        cin >> temp;

        v1.push_back(temp);
    }

    for (i = 0; i < n; i++) {
        if (v1[i] == -1) {
            v2[0] = i + 1;

            break;
        }
    }

    for (i = 0; i < v1.size(); i++) {
        if (v1[i] != -1 && v1[i] != v2[0]) {
            v2[v1[i]] = v1[i];
        }
    }

    for (i = 0; i < n; i++) {
        cout << v2[i] << " ";
    }

    return 0;
}