#include <bits/stdc++.h>
 
using namespace std;
 
double square(double n)
{
    return n * n;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << fixed << setprecision(2);

    int n, i, j;
    double d = 1e27;
 
    while (true) {
        cin >> n;
        
        if (n == 0) {
            break;
        }
     
        vector <pair <double, pair <double, double> > > v(n);
        pair <double, double> a, b;

        d = 1e27;
        
        for (i = 0; i < n; i++) {
            cin >> v[i].second.first >> v[i].second.second;
     
            v[i].first = v[i].second.first * v[i].second.first + v[i].second.second * v[i].second.second;
        }
     
        sort(v.begin(), v.end());
     
        for (i = 0; i < n; i++) {
            for (j = max(0, i - 50); j < min(n, i + 50); j++) {
                if (j != i) {
                    if (square(v[i].second.first - v[j].second.first) + square(v[j].second.second - v[i].second.second) < d) {
                        d = square(v[i].second.first - v[j].second.first) + square(v[j].second.second - v[i].second.second);
                        
                        a = v[i].second;
                        b = v[j].second;
                    }
                }
            }
        }
     
        cout << a.first << " " << a.second << " ";
        cout << b.first << " " << b.second << "\n";
    }
 
    return 0;
}