#include <iostream>
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };

class Solution {
public:
    ListNode* mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;

        if (l1->val > l2->val) {
            ListNode *tmp = l2;
            tmp->next = mergeTwoLists(l1, l2->next);
            return tmp;
        } else {
            ListNode *tmp = l1;
            tmp->next = mergeTwoLists(l1->next, l2);
            return tmp;
        }
    }
};
 */
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* r;
        ListNode* res;
        int jud=0;
        while(l1!=NULL&&l2!=NULL)
        {
            if(l1->val<l2->val)
            {
                r=l1;
                l1=l1->next;
                ++jud;
                if(jud==1) res=r;
            }
            else
            {
                r=l2;
                l2=l2->next;
                ++jud;
                if(jud==1) res=r;
            }
            r=r->next;
        }
        if(l1==NULL&&l2!=NULL)
        {
            r=l2;
            ++jud;
            if(jud==1) res=r;
        }
        if(l2==NULL&&l1!=NULL)
        {
            r=l1;
            ++jud;
            if(jud==1) res=r;
        }
        return res;
    }
};
int main() {

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
