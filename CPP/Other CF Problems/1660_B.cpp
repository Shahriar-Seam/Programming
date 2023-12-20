#include <bits/stdc++.h>

#define yes cout << "YES\n"
#define no cout << "NO\n"

using namespace std;

void solve()
{
    int n, temp;
    vector <int> arr;

    cin >> n;

    if (n == 1) {
        cin >> temp;

        if (temp == 1) {
            yes;
        }
        else {
            no;
        }
    }
    
    else {
        while (n--) {
            cin >> temp;

            arr.push_back(temp);
        }

        sort(arr.begin(), arr.end(), greater<int>());

        if (arr[0] == arr[1] || arr[0] == arr[1] + 1) {
            yes;
        }
        else {
            no;
        }
    }

    arr.clear();
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