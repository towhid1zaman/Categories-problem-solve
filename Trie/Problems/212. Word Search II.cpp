class Solution {
public:
    int getIndex(char c){
        return c - 'a';
    }
    struct TrieNode{
        bool isLeaf;
        TrieNode *child[26];
        TrieNode(): isLeaf(false){
            for(int i = 0; i < 26; i++){
                child[i] = NULL;
            }
        }
    };
    TrieNode* root = new TrieNode();

    void insert(string s){
        TrieNode *cur = root;
        for(int i = 0; i < s.size(); i++){
            int index = getIndex(s[i]);
            if(cur->child[index] == NULL){
                cur->child[index] = new TrieNode();
            }
            cur = cur->child[index];
        }
        cur->isLeaf = true;
    }
    
    const int dx4[4] = {0, 0, 1, -1}, dy4[4] = {1, -1, 0, 0};

    void dfs(vector<vector<char>>& board, int x, int y, int row, int col, TrieNode *node, string word, vector<string>& result){
        if(x < 0 || x >= row || y < 0 || y >= col || board[x][y] == '#') return;
        
        char curChar = board[x][y];
        node = node->child[getIndex(curChar)];
        if(node ==  NULL) return;
        
        word += board[x][y];;
        if(node->isLeaf){
            result.push_back(word);
            node->isLeaf = false; // avoid duplicate
        }

        board[x][y] = '#';
        
        for(int i = 0; i < 4; i++){
            int newX = x + dx4[i];
            int newY = y + dy4[i];
            dfs(board, newX, newY, row, col, node, word, result);
        }
        // dfs(board, x + 1, y, row, col, node, word, result);
        // dfs(board, x - 1, y, row, col, node, word, result);
        // dfs(board, x, y + 1, row, col, node, word, result);
        // dfs(board, x, y - 1, row, col, node, word, result);

        board[x][y] = curChar; // backtrack
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for(string word:words){
            insert(word);
        }
        int row = words.size(); // row
        int col = words[0].size(); // column

        TrieNode *rootNode = root;
        vector<string>result;

         for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                cout << i <<" "<<j<< endl;
                dfs(board, i, j, row, col, rootNode, "", result);
            }
        }
        return result;
    }
};
