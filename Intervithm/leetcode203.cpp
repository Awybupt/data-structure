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
    ListNode* removeElements(ListNode* head, int val) { 
        if(head==nullptr)
            return head;
        while((*head).val==val){
            head=(*head).next;
            if(head==nullptr)
                break;
        }
        ListNode* ans=head,* mid=head;
        while(head!=nullptr)
        {
            if((*head).val==val)
                (*mid).next=(*head).next;
            else
                mid=head;
            head=(*head).next;
        }
        return ans;
    }
};
