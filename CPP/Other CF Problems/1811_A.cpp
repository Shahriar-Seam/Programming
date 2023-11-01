#include <bits/stdc++.h>

using namespace std;

int main() {
    string str;
    int t, n, i;
    char k;
    
    cin >> t;
    
    while (t--) {
        cin >> n >> k;
        cin >> str;
        
        for (i = 0; i < n; i++) {
            if (str[i] < k) {
                break;
            }
        }
        
        str.insert(str.begin() + i, k);
        
        cout << str << "\n";
    }

    return 0;
}