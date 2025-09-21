// For Paging
// Input
// 	Process/Program Size
//              Page Size
//              Page Table Entry
//              Logical Address
// Output
// 	Physical Address

/*
32
4
5 6 1 2 -1 -1 -1 -1
4
2
7
9
20
*/

#include <bits/stdc++.h>

using namespace std;

int ceil_div(int n, int d)
{
    return (n + d - 1) / d;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int process_size, page_size, num_pages;
    int logical_address, physical_address;
    int page_num, offset, frame_num;
    int q, i;

    cin >> process_size >> page_size;

    num_pages = ceil_div(process_size, page_size);

    cout << "Process size: " << process_size << "\n";
    cout << "Page size: " << page_size << "\n";
    cout << "Number of pages: " << num_pages << "\n";

    vector <int> pages(num_pages);

    for (auto &it : pages) {
        cin >> it;
    }

    cout << "Page Table:\n";
    cout << "Page : Frame\n";

    for (i = 0; i < num_pages; i++) {
        cout << i << "\t:\t" << pages[i] << "\n";
    }

    cin >> q;

    cout << "Number of logical addresses to be transformed: " << q << "\n\n";

    while (q--) {
        logical_address;
        cin >> logical_address;

        if (logical_address >= process_size) {
            cout << "Invalid logical address: " << logical_address << "\n";

            continue;
        }

        page_num = logical_address / page_size;
        offset = logical_address % page_size;

        frame_num = pages[page_num];

        if (frame_num == -1) {
            cout << "Page hasn't been loaded into frame yet for Logical Address: " << logical_address << "\n";

            continue;
        }

        physical_address = frame_num * page_size + offset;

        cout << "Physical Address: " << physical_address << " for Logical Address: " << logical_address << "\n";
    }

    return 0;
}