//Based on https://lightoj.com/problem/ghajini

#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define int long long
#define MAXN 100005

struct mxmn {
	int maxVal;
	int minVal;
};
int nums[MAXN];
mxmn tree[4 * MAXN];


int left(int node) { return 2 * node + 1; }
int right(int node) { return 2 * node + 2; }
int half(int left, int right) { return left + (right - left) / 2; }

void build(int node, int b, int e) {
	if (b == e) {
		tree[node].maxVal = nums[b];
		tree[node].minVal = nums[b];
		return;
	}

	int mid = half(b, e);
	build(left(node), b, mid);
	build(right(node), mid + 1, e);
	tree[node].maxVal = max(tree[left(node)].maxVal, tree[right(node)].maxVal);
	tree[node].minVal = min(tree[left(node)].minVal, tree[right(node)].minVal);
}

int mxQuery(int node, int b, int e, int l, int r) {
	if (e < l || b > r)return INT_MIN;
	if (l <= b && e <= r) {
		return tree[node].maxVal;
	}
	int mid = half(b, e);
	int Left = mxQuery(left(node), b, mid, l, r);
	int Right = mxQuery(right(node), mid + 1, e, l, r);
	return max(Left, Right);
}
int mnQuery(int node, int b, int e, int l, int r) {
	if (e < l || b > r)return INT_MAX;
	if (l <= b && e <= r) {
		return tree[node].minVal;
	}
	int mid = half(b, e);
	int Left = mnQuery(left(node), b, mid, l, r);
	int Right = mnQuery(right(node), mid + 1, e, l, r);
	return min(Left, Right);
}
void solve(int t) {
	int n, q;  cin >> n >> q;
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	n -= 1;
	//q -= 1;
	build(0, 0, n);
	int ans = INT_MIN;
	for(int i = 0; i < n; i++){
        int now = mxQuery(0, 0, n, i, (i+q-1)) - mnQuery(0, 0, n, i, (i+q-1));
        ans = max(ans, now);
	}

	cout << "Case " << t << ": " << ans << endl;
}
void reset() {
	memset(nums, 0, sizeof nums);
	for (int i = 0; i < MAXN; i++) {
		tree[i].maxVal = INT_MIN;
		tree[i].minVal = INT_MAX;
	}
}
 main() {
	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		reset();
		solve(t);
	}
}
