/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 
 https://leetcode.com/problems/linked-list-cycle/
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head)return false;
        ListNode *slowPos = head;
        ListNode *fastPos = head;
        while(fastPos and fastPos->next){
            slowPos = slowPos->next;
            fastPos = fastPos->next->next;
            if(slowPos == fastPos){
                return true;
            }
        }
        return false;
    }
};
