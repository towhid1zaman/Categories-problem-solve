// based on https://lightoj.com/problem/curious-robin-hood
#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005
#define blockSize 300

int nums[MAXN];
int block[MAXN];

void build(int n) {
	for (int i = 0; i < n; i++) {
		block[i / blockSize] += nums[i];
	}
}
void update(int pos, int newValue) {
	block[pos / blockSize] -= nums[pos];
	nums[pos] += newValue;
	block[pos / blockSize] += nums[pos];
}
int query(int l, int r) {
	int ans = 0;
	for (int i = l; i <= r;) {
		if (i % blockSize == 0 && i + blockSize - 1 <= r) {
			ans += block[i / blockSize];
			i += blockSize;
		}
		else {
			ans += nums[i];
			i +=1;
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
		int c; 
		cin >> c;
		if (c == 1) {
			int p; cin >> p;
			int ans = nums[p];
			block[p / blockSize] -= nums[p];
			nums[p] = 0;
			cout << ans << endl;
		}
		else if (c == 2) {
			int p, val; cin >> p >> val;
			update(p, val);
		}
		else {
			int l, r; cin >> l >> r;
			int ans = query(l, r);
			cout << ans << endl;
		}
	}
}
void reset() {
	for (int i = 0; i <= MAXN; i++) {
		block[i] = 0;
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
