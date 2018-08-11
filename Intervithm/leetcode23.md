## Merge k Sorted Lists
* Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

```
Example:

Input:
[
  1->4->5,
  1->3->4,
  2->6
]
Output: 1->1->2->3->4->4->5->6
```

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int llen=lists.size();
        if(llen==0)
            return nullptr;
        else if(llen==1)
            return lists[0];
        else
        {
            ListNode *head=lists[0];
            for(int i=1;i<llen;i++)
            {
                ListNode *temp=head,*ins=lists[i];
                
                if(!ins)
                    continue;
                
                if(!head){
                    head=ins;
                    continue;
                }
                
                ListNode *ans;
                
                if(head->val>ins->val){
                    ans=ins;
                    ins=ins->next;
                }
                else{
                    ans=temp;
                    temp=temp->next;
                }
                
                ListNode *rans=ans;
                
                while(temp&&ins){
                    if(temp->val<ins->val){
                        ans->next=temp;
                        temp=temp->next;
                        ans=ans->next;
                    }
                    else
                    {
                        ans->next=ins;
                        ins=ins->next;
                        ans=ans->next;
                    }
                }
               
                if(temp)
                    ans->next=temp;
                else
                    ans->next=ins;
                
                head=rans;  
            }
            return head;
        }
    }
};
```
