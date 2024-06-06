#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(13);
    
    long long n;
    vector <double> v;
    
    while(cin >> n) {
        v.push_back((double) sqrt((double) n));
    }
    
    for (auto it = v.rbegin(); it != v.rend(); it++) {
        cout << *it << "\n";
    }
    
    return 0;
}