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
    ListNode *reverseFromMiddle(ListNode *head){
        ListNode *dummyHead = NULL;
        while(head){
            ListNode *nextNode = head->next;
            head->next = dummyHead;
            dummyHead = head;
            head = nextNode;
        }
        return dummyHead;
    }
    void reorderList(ListNode* head) {
        if(!head or !head->next){
            return;
        }
        ListNode *slowPointer = head;
        ListNode *fastPointer = head;
        while(fastPointer and fastPointer->next){
            slowPointer = slowPointer->next;
            fastPointer = fastPointer->next->next;
        }
        
        slowPointer = reverseFromMiddle(slowPointer);

        ListNode *curHead = head;
        while(slowPointer->next){
            ListNode *nextNode = curHead->next;     
            curHead->next = slowPointer;
            curHead = nextNode;

            nextNode = slowPointer -> next;
            slowPointer->next = curHead;
            slowPointer = nextNode;
        }
    }
};
