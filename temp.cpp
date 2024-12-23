#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n, a, b, c;
        cin >> n >> a >> b >> c;
        
        long long total_distance = a + b + c;
        int full_cycles = n / total_distance;
        int day = full_cycles * 3;
        long long remaining_distance = n % total_distance;
        
        vector<long long> distances = {a, b, c};
        for (int i = 0; remaining_distance > 0; ++i) {
            remaining_distance -= distances[i];
            day++;
        }
        
        cout << day << endl;
    }
    return 0;
}