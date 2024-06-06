#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i, temp, mex;
    vector <int> v;
    set <int> s;

    cin >> n;
    
    for (i  = 0; i < n; i++) {
        cin >> temp;

        v.push_back(temp);
    }

    priority_queue <int, vector <int>, greater <int> > pq(v.begin(), v.end());

    i = 0;
    while (pq.empty() == false) {
        if (i % 2 == 0) {
            s.insert(pq.top());

            pq.pop();
        }
        else {
            pq.pop();
        }

        i++;
    }

    i = 0;
    set <int> :: iterator it;

    it = s.end();
    it--;

    mex = *it + 1;
    for (auto it = s.begin(); it != s.end(); it++) {        
        if (*it != i) {
            mex = i;

            break;
        }

        i++;
    }

    cout << mex << "\n";
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