#include <bits/stdc++.h>
using namespace  std;
 
#define ll long long


void solve() {
    int m, n; cin >> m >> n;
    char arr[m][n];

    bool pre_possible = true;

    for(int i = 0; i < m; i++) {
        for(int j = 0 ; j < n ; j++) {
            cin >> arr[i][j];
        }
    }

    int mat[m][n];

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            mat[i][j] = arr[i][j] - '0';
        }
    }

    bool possible = true;

    for(int i = 0  ; i < m; i++) {
        for(int j = 0; j < n; j++) {
          
            if(mat[i][j] == 1) {
                //cout << "yo\n";
            //    cout << i << ' ' << j << '\n';
                int val1 = 1, val2 = 1;
                for(int p = 0; p <= i; p++) {
                    val1 *= mat[p][j];
                }
                //cout << val1 << '\n';
                for(int p = 0; p <= j; p++) {
                    val2 *= mat[i][p];
                }

             //   cout << val2 << '\n';

                if(val1+val2 == 0) possible = false;

            }
         }
   
    }

    if(possible) cout << "YES";
    else cout << "NO";

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
