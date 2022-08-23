/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 https://leetcode.com/problems/remove-nth-node-from-end-of-list/
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *curNode = head;
        int listLength = 0;
        while(curNode){
            curNode = curNode->next;
            listLength++;
        }
        n = listLength - n;
        if(n == 0){
           head = head->next;
           return head;
        }
        curNode = head;
        while(curNode and n > 1){
            curNode = curNode->next;
            n--;
        }

        ListNode *newNode;
        if(curNode->next->next == NULL){
            curNode->next = NULL;
        }else {
            newNode = curNode->next->next;
            curNode->next = newNode;
        }
        return head;
    }
};
