#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    long long n;
    long long i, count = 0;
 
    cin >> n;
 
    vector <long long> v(n), prefix(n + 1, 0);
    map <long long, long long> mp; // occurrences of prefixes
 
    for (auto &it : v) {
        cin >> it;
    }
 
    for (i = 0; i < n; i++) {
        prefix[i + 1] = ((prefix[i] + v[i]) % n + n) % n; // all positive
    }
 
    for (i = 0; i <= n; i++) {
        count += mp[prefix[i]];
        mp[prefix[i]]++;
    }
 
    cout << count;
 
    return 0;
}