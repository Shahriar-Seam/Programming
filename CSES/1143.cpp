#include <bits/stdc++.h>

using namespace std;

#define int long long

const int sz = 2e6 + 5;

struct node {
	int mn, mx;
};

int arr[sz];
node tree[sz * 4];
int n;
int p2;

// node def = {1e12, -1};

void calc_p2()
{
    p2 = 1;

    while (p2 < n) {
        p2 *= 2;
    }
}

node f(node a, node b)
{
	return {min(a.mn, b.mn), max(a.mx, b.mx)};
}

void build()
{
	int i;

	for (i = 0; i < sz * 4; i++) {
		tree[i] = {1000000000000, -1};
	}

	for (i = 0; i < p2; i++) {
		tree[i + p2] = {arr[i], arr[i]};
	}

	for (i = p2 - 1; i > 0; i--) {
		tree[i] = f(tree[i * 2], tree[i * 2 + 1]);
	}
}

void get(int v, int &ind, int i)
{
	if (i >= 4 * n) {
		return;
	}

	node t = tree[i];

	if (v <= t.mx) {
		if (i < p2) {
			t = tree[i * 2];

			if (v <= t.mx) {
				get(v, ind, i * 2);
			}
			else if (v <= tree[i * 2 + 1].mx) {
				get(v, ind, i * 2 + 1);
			}
		}
		else {
			ind = i - p2 + 1;

			tree[i].mn -= v;
			tree[i].mx -= v;
		}
	}

	if (i < p2) {
		tree[i] = f(tree[i * 2], tree[i * 2 + 1]);
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    
	int m;
    
	cin >> n >> m;
    
	for (int i = 0; i < n; i++) {
        cin >> arr[i];
	}
    
    calc_p2();
	build();

	while (m--) {
		int x, ind = 0;

		cin >> x;

		get(x, ind, 1);

		cout << ind << " ";
	}

	return 0;
}