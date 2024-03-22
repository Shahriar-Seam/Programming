#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, temp, i;
    deque <int> dq;

    cin >> n;

    for (i = 0; i < n; i++) {
        cin >> temp;
        
        if (dq.empty() == true) {
            dq.push_back(temp);
        }
        else {
            if (dq.front() > temp) {
                dq.push_front(temp);
            }
            else {
                dq.push_back(temp);
            }
        }
    }

    for (auto it : dq) {
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