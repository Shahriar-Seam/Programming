#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;

    cin >> n >> q;

    vector <int> v(q), box(n + 1, 0), box_num;

    for (auto &it : v) {
        cin >> it;
    }

    for (auto &it : v) {
        if (it >= 1) {
            box[it]++;
            box_num.push_back(it);
        }
        else {
            int i, min_cnt = 1e9, index = 0;

            for (i = 1; i <= n; i++) {
                if (box[i] < min_cnt) {
                    index = i;
                    min_cnt = box[i];
                }
            }

            box[index]++;
            box_num.push_back(index);
        }
    }

    for (auto it : box_num) {
        cout << it << " ";
    }
    
    cout << "\n";

    return 0;
}