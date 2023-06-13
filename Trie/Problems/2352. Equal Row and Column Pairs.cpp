class Solution {
public:
    struct trie{
        int leaf;
        unordered_map<int, trie*>child;
        trie(){
            leaf = 0;
            child.clear();
        }
    }*root;
    void insert(vector<int>&a){
        trie *cur = root;
        for(int i = 0; i < a.size(); i++){
            if(cur->child.find(a[i]) == cur->child.end()){
                cur->child[a[i]] = new trie();
            }
            cur = cur->child[a[i]];
        }
        cur->leaf+=1;
    }
    int search(vector<int>&a){
        trie *cur = root;
        for(int i = 0; i < a.size(); i++){
            if(cur->child.find(a[i]) == cur->child.end()){
                return 0;
            }
            cur = cur->child[a[i]];
        }
        return cur->leaf;
    }
    int equalPairs(vector<vector<int>>& grid) {
        root = new trie();
        int ans = 0;
        for(vector<int> row:grid){
            insert(row);
        }
        for(int i = 0; i < grid[0].size(); i++){
            vector<int>col;
            for(int j = 0; j < grid.size(); j++){
                col.push_back(grid[j][i]);
            }
            ans += search(col);
        }
        return ans;
    }
};
