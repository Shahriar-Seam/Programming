#include <bits/stdc++.h>

using namespace std;

int sum(vector <int> &v, int n, int index)
{
    if (index < n) {
        return v[index] + sum(v, n, index + 1);
    }
    else {
        return 0;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int testCases, caseNo, n, i, temp;
    vector <int> v;

    cin >> testCases;

    for (caseNo = 1; caseNo <= testCases; caseNo++) {
        v.clear();

        cin >> n;

        for (i = 0; i < n; i++) {
            cin >> temp;

            v.push_back(temp);
        }

        cout << "Case " << caseNo << ": " << sum(v, n, 0) << "\n";
    }

    return 0;
}