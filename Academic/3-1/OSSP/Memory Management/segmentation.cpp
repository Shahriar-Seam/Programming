// For Segmentation
// Input
// 	Number of Segment
//              Size of Each Segment
//              Segment Table Entry
//              Logical Address  
//              Logical Address (Segment Number and Offset)
// Output
// 	Physical Address

/*
5
1400 6300 4300 3200 4700
1000 400 400 1100 1000
3
2 53
3 852
0 1222
*/

#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int num_segments;
    int i;
    int base, offset;
    int physical_address;
    
    cin >> num_segments;

    cout << "Number of segments: " << num_segments << "\n";

    vector <int> segment_table(num_segments);
    vector <int> segment_size(num_segments);

    for (i = 0; i < num_segments; i++) {
        cin >> segment_table[i];
    }

    for (i = 0; i < num_segments; i++) {
        cin >> segment_size[i];
    }

    cout << "Segment Table:\n";
    cout << "Base : Limit" << "\n";

    for (i = 0; i < num_segments; i++) {
        cout << segment_table[i] << " : " << segment_size[i] << "\n";
    }

    int q;

    cin >> q;

    cout << "Number of logical addresses to be transformed: " << q << "\n\n";

    while (q--) {
        cin >> base >> offset;

        if (base >= num_segments) {
            cout << "Invalid segment number: " << base << "\n";
            
            continue;
        }

        if (offset >= segment_size[base]) {
            cout << "Invalid offset: " << offset << " for segment number: " << base << "\n";

            continue;
        }

        physical_address = segment_table[base] + offset;

        cout << "Physical Address: " << physical_address << " for Logical Address: (" << base << ", " << offset << ")\n";
    }

    return 0;
}