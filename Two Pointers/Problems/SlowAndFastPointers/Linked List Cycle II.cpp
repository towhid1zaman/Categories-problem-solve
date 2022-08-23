/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//https://leetcode.com/problems/linked-list-cycle-ii/
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head){
            return NULL;
        }
        ListNode *slowPos = head;
        ListNode *fastPos = head;
        ListNode *startPos = head;

        while(fastPos and fastPos->next){
            slowPos = slowPos->next;
            fastPos = fastPos->next->next;
            if(slowPos == fastPos){ // found cycle
                
                while(startPos != slowPos){//finding startPos
                    startPos = startPos->next;
                    slowPos = slowPos->next;
                }
                return startPos;
            
            }
        }
        return NULL;
    }
};
