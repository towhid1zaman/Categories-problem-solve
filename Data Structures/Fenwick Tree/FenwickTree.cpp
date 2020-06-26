
struct FenwickTree{
	int N;
	vector<int> tree;

	void build(int n){
		N = n;
		tree.assign(n + 1, 0);
	}

	void update(int idx, int val){
		while (idx <= N)
		{
			tree[idx] += val;
			idx += idx & -idx;
		}
	}

	void updateMax(int idx, int val){
		while (idx <= N)
		{
			tree[idx] = max(tree[idx], val);
			idx += idx & -idx;
		}
	}
     //mainly Query
	int pref(int idx){
		int ans = 0;
		while (idx > 0){
			ans += tree[idx];
			idx -= idx & -idx;
		}
		return ans;
	}
     //range sum
	int rsum(int l, int r){
		return pref(r) - pref(l - 1);
	}

	int prefMax(int idx){
		int ans = -2e9;
		while (idx > 0){
			ans = max(ans, tree[idx]);
			idx -= idx & -idx;
		}
		return ans;
	}
};
