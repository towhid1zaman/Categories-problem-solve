/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(!head or head->next == NULL){
            return NULL;    
        }
        ListNode *slowPointer = head;
        ListNode *fastPointer = head;
        
        while(fastPointer->next->next and fastPointer -> next -> next->next){
            slowPointer=slowPointer->next;
            fastPointer = fastPointer ->next ->next;
        }
        
        slowPointer->next = slowPointer->next->next;
        return head;
    }
};
