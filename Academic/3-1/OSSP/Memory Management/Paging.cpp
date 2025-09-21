// For Paging
// Input
// 	Process/Program Size
//              Page Size
//              Page Table Entry
//              Logical Address
// Output
// 	Physical Address

// 16
// 4
// 5 6 1 2
// 4
// 2
// 7
// 9
// 20

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
    int q;

    cin >> process_size >> page_size;

    num_pages = ceil_div(process_size, page_size);

    vector <int> pages(num_pages);

    for (auto &it : pages) {
        cin >> it;
    }

    cin >> q;

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
        physical_address = frame_num * page_size + offset;

        cout << "Physical Address: " << physical_address << " for Logical Address: " << logical_address << "\n";
    }

    return 0;
}