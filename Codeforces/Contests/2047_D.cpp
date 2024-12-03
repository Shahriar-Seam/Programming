#include <bits/stdc++.h>

using namespace std;

vector <int> func(vector <int> &v)
{
    int n = v.size();
    int mi, i;
    deque <int> dq;
    priority_queue <int, vector <int>, greater <int> > pq;

    mi = v.back();
    dq.push_front(mi);

    for (i = n - 2; i >= 0; i--) {
        if (v[i] > mi) {
            pq.push(v[i]);
        }
        else {
            dq.push_front(v[i]);
            mi = min(mi, v[i]);

            while (!pq.empty()) {
                dq.push_back(pq.top() + 1);

                pq.pop();
            }
        }
    }

    while (!pq.empty()) {
        dq.push_back(pq.top() + 1);

        pq.pop();
    }

    vector <int> vv(dq.begin(), dq.end());

    return vv;
}

void solve()
{
    int n, i, j, mi;
    deque <int> dq;
    priority_queue <int, vector <int>, greater <int>> pq;

    cin >> n;

    vector <int> v(n), temp;

    for (auto &it : v) {
        cin >> it;
    }

    v = func(v);
    v = func(v);
    
    for (auto it : v) {
        cout << it << " ";
    }

    cout << "\n";
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