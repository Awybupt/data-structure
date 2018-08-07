/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *lastptr=NULL,* realptr;
        while(head != NULL)
        {
            realptr = (*head).next;
            (*head).next = lastptr;
            lastptr = head;
            head = realptr;
        }
        return lastptr;
    }
};
