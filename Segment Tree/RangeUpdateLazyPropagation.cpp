// based on https://lightoj.com/problem/horrible-queries

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 100005

int nums[MAXN];
int tree[4*MAXN];
int lazy[4*MAXN];

int left(int node) { return 2 * node + 1; }
int right(int node) { return 2 * node + 2; }

// no need for this problem
void build(int node, int b, int e) {
	if (b == e) {
		tree[node] = nums[b];
		return;
	}

	int mid = b + (e - b) / 2;
	build(left(node), b, mid);
	build(right(node), mid + 1, e);
	tree[node] = tree[left(node)] + tree[right(node)];
}

void clearPreviousCalculations(int node, int b, int e) {
	if (lazy[node] > 0) {
		tree[node] += (e - b + 1)*lazy[node];
		
		if(b!=e){
            lazy[left(node)] += lazy[node];
            lazy[right(node)] += lazy[node];
		}
        lazy[node] = 0;
	}
}
void updateRange(int node, int b, int e, int l, int r, int newVal) {
	clearPreviousCalculations(node, b, e);

	if (e < l || b > r || b > e)return;
	if (l <= b && e <= r) {
		lazy[node] += newVal;
		clearPreviousCalculations(node, b, e);
		return;
	}

	int mid = b + (e - b) / 2;
	updateRange(left(node), b, mid, l, r, newVal);
	updateRange(right(node), mid + 1, e, l, r, newVal);
	tree[node] = tree[left(node)] + tree[right(node)];
}

int queryRange(int node, int b, int e, int l, int r) {
	clearPreviousCalculations(node, b, e);

	if (e < l || b > r || b > e)return 0;
	if (l <= b && e <= r) {
		return tree[node];
	}

	int mid = b + (e - b) / 2;
	int x = queryRange(left(node), b, mid, l, r);
    int y = queryRange(right(node), mid + 1, e, l, r);
    return x + y;
}
void solve(int t) {
	int n, q;  cin >> n >> q;
	n -= 1;
	//build(0, 0, n);
	cout << "Case " << t << ":" << endl;
	while (q--) {
		int command;
		cin >> command;
		if (command == 0) {
			int x, y, v; cin >> x >> y >> v;
			updateRange(0, 0, n, x, y, v);
		}
		else if (command == 1) {
			int x, y; cin >> x >> y;
			int  ans = queryRange(0, 0, n, x, y);
			cout << ans << endl;
		}
	}
}
void reset() {
	memset(nums, 0, sizeof nums);
	memset(tree, 0, sizeof tree);
	memset(lazy, 0, sizeof lazy);
}
main() {
	int T; cin >> T;
	for (int t = 1; t <= T; t++){
		reset();
		solve(t);
	}
}
