#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        
        // Create pattern [n, n/2, n/2, n, n/2, n/2, ...]
        // This ensures many palindromic subsequences of length 4
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            if (i % 3 == 0) {
                a[i] = n;
            } else {
                a[i] = n/2 + 1;  // using n/2 + 1 to ensure it's valid when n is odd
            }
        }
        
        // Print the sequence
        for (int i = 0; i < n; i++) {
            cout << a[i] << (i == n-1 ? '\n' : ' ');
        }
    }
    return 0;
}
