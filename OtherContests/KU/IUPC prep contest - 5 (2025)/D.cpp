#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int l1, l2, x, y, i, j, k, length = 0, len = 0;
    vector <pair <int, int> > v1, v2;
    map <pair <int, int>, int> mp;

    cin >> l1;

    for (i = 0; i < l1; i++) {
        cin >> x >> y;
     
        v1.push_back({x, y});

        mp[{x, y}] = i;
    }

    cin >> l2;

    for (i = 0; i < l2; i++) {
        cin >> x >> y;

        v2.push_back({x, y});
    }

    for (i = 0; i < l2; i++) {
        if (mp.find(v2[i]) != mp.end()) {
            length = max(length, 1);

            j = mp[v2[i]];

            len = 0;
            k = i;

            if (j > 0 && i < l2 - 1 && v1[j - 1] == v2[i + 1]) {
                // up

                for (j; j >= 0 && k < l2; j--, k++) {
                    if (v1[j] == v2[k]) {
                        len++;
                    }
                    else {
                        break;
                    }
                }

                length = max(length, len);
            }
            if (j < l1 - 1 && i < l2 - 1 && v1[j + 1] == v2[i + 1]) {
                // down

                for (j; j < l1 && k < l2; j++, k++) {
                    if (v1[j] == v2[k]) {
                        len++;
                    }
                    else {
                        break;
                    }
                }

                length = max(length, len);
            }

            if (k > i) {
                i = k - 1;
            }
        }
    }

    cout << length << "\n";

    return 0;
}