#include <iostream>
#include <math.h>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 * class Solution {//第一种
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int a1=0,a2=0;
        ListNode* ans;
        for(int i=0;l1!=NULL;i++)
        {
            a1=a1+l1->val*((int)pow(10,i));
        }
        for(int i=0;l2!=NULL;i++)
        {
            a2=a2+l2->val*((int)pow(10,i));
        }
        int temp=a1+a2;
        ListNode* a;
        a=ans;
        while(temp>0)
        {
            a1=temp-(temp/10)*10;
            ans=new ListNode(a1);
            ans=ans->next;
            temp=temp/10;
        }
        return a;
    }
};
 class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans;
        int jdg=0;//进位信号
        while(l1!=NULL||l2!=NULL||jdg!=0)
        {
            if(l1!=NULL&&l2!=NULL)
            {
                ans=new ListNode((l1->val+l2->val+jdg)/10);
                if((l1->val+l2->val+jdg)>9)
                    jdg=1;
                else
                    jdg=0;
                l1=l1->next;
                l2=l2->next;
            }
            else if(l1==NULL&&l2!=NULL)
            {
                ans=new ListNode((l2->val+jdg)/10);
                if(l2->val+jdg>9)
                    jdg=1;
                else
                    jdg=0;
                l2=l2->next;
            }
            else if(l2==NULL&&l1!=NULL)
            {
                ans=new ListNode((l1->val+jdg)/10);
                if(l1->val+jdg>9)
                    jdg=1;
                else
                    jdg=0;
                l1=l1->next;
            }
            else if(jdg!=0)
                ans=new ListNode(1);
            else
                return ans;
        }
    }
};
 ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode preHead(0), *p = &preHead;
    int extra = 0;
    while (l1 || l2 || extra) {
        int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + extra;
        extra = sum / 10;
        p->next = new ListNode(sum % 10);
        p = p->next;
        l1 = l1 ? l1->next : l1;
        l2 = l2 ? l2->next : l2;
    }
    return preHead.next;
}
 */
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode preHead(0), *p = &preHead;
        int extra = 0;
        while (l1 || l2 || extra) {
            int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + extra;
            extra = sum / 10;
            p->next = new ListNode(sum % 10);
            p = p->next;
            l1 = l1 ? l1->next : l1;
            l2 = l2 ? l2->next : l2;
        }
        return preHead.next;
    }
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
