#include <bits/stdc++.h>
using namespace  std;
 
#define ll long long


void solve() {
    int n(500); //cin >> n;
    char c('r'); //cin >> c;

    string s; //cin >> s;

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            s += 'y';
        }
        else {
            s += 'r';
        }
    }

    s[499] = 'g';

    s = s + s;  

    int i = 0, j = 0;
    int max_dis = INT_MIN;

    if(n == 1) {
        cout << 0;
        return;
    }
    int cnt = 0;
    while(i < n and j < 2 * n) {
        if(s[i] != c) {
            i++;
            j = i;
            cnt++;
        }
        else{
            if(s[j] != 'g') {
                j++;
                cnt++;
            }
            else{
                max_dis = max(max_dis, j-i);
                i++;
                cnt++;
            }
        }
    }

    cout << max_dis << '\n';
    cout << cnt ;

    //cout << s.size();
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
 
    int t; cin >> t;

    while(t--) {
        solve();
        cout << '\n';
    }
}
