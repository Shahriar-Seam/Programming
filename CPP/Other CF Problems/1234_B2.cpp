#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, id;

    cin >> n >> k;

    map <int, int> marked;
    deque <int> dq;

    while (n--) {
        cin >> id;

        if (!marked[id]) {
            marked[id] = 1;

            dq.push_front(id);
        }

        if (dq.size() > k) {
            marked[dq.back()] = 0;

            dq.pop_back();
        }
    }

    cout << dq.size() << "\n";

    for (auto &it : dq) {
        cout << it << " ";
    }

    cout << "\n";

    return 0;
}