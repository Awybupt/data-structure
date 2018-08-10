## Linked List Cycle

* Given a linked list, determine if it has a cycle in it.

  * Follow up:
  * Can you solve it without using extra space?

```cpp
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
    bool hasCycle(ListNode *head) {
        ListNode* one=head,* two=head;
        while(two)
        {
            one=one->next;
            two=two->next;
            if(two==nullptr)
                return false;
            two=two->next;
            if(one == two)
                return true;
        }
        return false;
    }
};
```
