//https://leetcode.com/problems/partition-labels/
class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>markIndex(26, 0);
        for(int i = 0; i<s.size(); i++){
            markIndex[s[i]-'a'] = i;
        }
        int endPos = markIndex[s[0]-'a'];
        int curSize = 1;
        vector<int>ans;
        for(int i = 0; i<s.size(); i++){
            if(markIndex[s[i]-'a'] > endPos){
                endPos = markIndex[s[i] - 'a'];
            }
            if(i == endPos){
                ans.push_back(curSize);
                curSize = 0;
            }
            curSize++;
        }
        return ans;
    }
};
