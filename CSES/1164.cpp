#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n, i, j, a, b, k = 0;
 
    cin >> n;
 
    vector <tuple <int, int, int> > v(n);
    vector <pair <int, int> > rooms;
    set <int> unoccupied;
    multiset <pair <int, int> > occupied;
 
    for (i = 0; i < n; i++) {
        cin >> a >> b;
 
        v[i] = {a, b, i};
    }
 
    sort(v.begin(), v.end());
 
    rooms.push_back({get <2> (v[0]), 1});
    
    occupied.insert({get <1> (v[0]), 1});
    
    for (i = 2; i <= n; i++) {
        unoccupied.insert(i);
    }
 
    for (i = 1; i < n; i++) {
        while (!occupied.empty() && occupied.begin()->first < (get <0> (v[i]))) {
            unoccupied.insert(occupied.begin()->second);
 
            occupied.erase(occupied.begin());
        }
        
        rooms.push_back({get <2> (v[i]), *unoccupied.begin()});

        unoccupied.erase(unoccupied.begin());
        occupied.insert(make_pair((get <1> (v[i])), rooms.back().second));
    }
 
    sort(rooms.begin(), rooms.end());
 
    for (auto it : rooms) {
        k = max(k, it.second);
    }
 
    cout << k << "\n";
 
    for (auto it : rooms) {
        cout << it.second << " ";
    }
 
    return 0;
}