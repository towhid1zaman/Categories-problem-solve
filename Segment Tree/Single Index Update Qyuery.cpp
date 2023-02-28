class NumArray {
public:
    #define maxNode 120000
    int n;
    int nums[100000];
    int buildTree[maxNode]; // 0 indexed

    void build(int node, int left, int right) {
        if (left == right) { // this is leaf node
            buildTree[node] = nums[left];
            return;
        }
        int mid = left + (right - left) / 2;
        int leftNode = 2 * node + 1;
        int rightNode = 2 * node + 2;
        build(leftNode, left, mid); // leftChild recursion
        build(rightNode, mid + 1, right); // rightChild recursion

        // after completing left and right tree calculation, make sum and store it to current node
        buildTree[node] = buildTree[leftNode] + buildTree[rightNode];
    }

    void update(int node, int left, int right, int index, int val) {
        if(index < left || index > right) return; // outside of range
        
        if (left == right) {
            if(left == index) buildTree[node] = val;
            return;
        }
        int mid = left + (right - left) / 2;
        int leftNode = 2 * node + 1;
        int rightNode = 2 * node + 2;
        update(leftNode, left, mid, index, val);
        update(rightNode, mid + 1, right, index, val);
        // after completing left and right tree calculation, make sum and store it to current node
        buildTree[node] = buildTree[leftNode] + buildTree[rightNode];
    }

    // current node in tree, query left, query right, array start from 0 to N-1
    int query(int node, int left, int right, int ql, int qr) {
        // outside the range
        if (qr < left || right < ql) return 0;

        if (ql <= left && qr >= right) {
            // inside the given range
            return buildTree[node];
        }
        
        int mid = left + (right - left) / 2;
        // int leftResult = query(2 * node + 1, left, mid, ql, qr);
        // int rightResult = query(2 * node + 2, mid + 1, right, ql, qr);
       // return leftResult + rightResult;
       return query(2 * node + 1, left, mid, ql, qr) + query(2 * node + 2, mid + 1, right, ql, qr);
    }

    NumArray(vector<int>& num) {
        n = num.size();
        for(int i = 0; i < n; i++){
            nums[i] = num[i];
        }
        build(0, 0, n-1);
    }
    
    void update(int index, int val) {
        update(0, 0, n-1, index, val);
    }
    
    int sumRange(int left, int right) {
        int res = query(0, 0, n-1, left, right);
        return res;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
