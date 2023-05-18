//based on https://lightoj.com/problem/array-queries

#include<iostream>
#include<algorithm>
using namespace std;
#define MAXN 100005
#define blockSize 300

int nums[MAXN];
int block[MAXN];
void build(int n) {
	for (int i = 0; i < n; i++) {
		block[i / blockSize] = min(block[i / blockSize], nums[i]);
	}
}
void update(int pos, int newValue) {
	// for sum
	block[pos / blockSize] -= newValue;
	nums[pos] = newValue;
	block[pos / blockSize] += newValue;
}
int query(int l, int r) {
	int ans = INT_MAX;
	for (int i = l; i <= r;) {
		if (i % blockSize == 0 && i + blockSize - 1 <= r) {
			ans = min(ans, block[i / blockSize]);
			i += blockSize;
		}
		else {
			ans = min(ans, nums[i]);
			i++;
		}
	}
	return ans;
}
void solve(int t) {
	int n, q; cin >> n >> q;
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	build(n);
	cout << "Case " << t << ":" << endl;
	while (q--) {
		int l, r; cin >> l >> r;
		l--, r--;
		int ans = query(l, r);
		cout << ans << endl;
	}
}
void reset() {
	for (int i = 0; i <= MAXN; i++) {
		block[i] = INT_MAX;
		nums[i] = 0;
	}
}
int main() {
	int T; cin >> T;
	for (int t = 1; t <= T; t++){
		reset();
		solve(t);
	}
}
