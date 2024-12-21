#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int find_mex(const vector<int>& arr, int k) {
    set<int> s(arr.begin(), arr.end());
    int mex = 0;
    while (k > 0) {
        if (s.find(mex) == s.end()) {
            k--;
        }
        mex++;
    }
    while (s.find(mex) != s.end()) {
        mex++;
    }
    return mex;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cout << find_mex(arr, k) << endl;
    }
    return 0;
}