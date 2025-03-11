#include <bits/stdc++.h>
using namespace  std;
 
#define ll long long
#define int long long


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
 
    ll n;

    while(cin >> n) {
        if(n == 0) break;
        
        int cnt = 0;
        while((n & 1) == 0) {
            cnt++;
            n >>= 1;
         //   cout << "yo\n";
        }
     //   cout << cnt <<'\n';
        if(cnt > 0) cout << 2 << '^' << cnt <<' ';

        int lim = 1e7 + 50;

        for(int i = 3; i <= lim; i+=2) {
            if(n % i == 0) {
                int cnt = 0;
                while(n % i == 0) {
                    cnt++;
                    n /= i;
                }
                cout << i << '^' << cnt <<' ';
            }
        }
        if(n > 1) cout << n << '^' << 1;
        cout << '\n';
    }
    
}