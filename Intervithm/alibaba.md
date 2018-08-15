# 面试

## 反转链表

```cpp
#include <iostream>

typedef struct Node{
  int val;
  struct Node * next;
}node;

node * revese(node * head)
{
  node * last = nullptr,* ans=nullptr;
  while(head)
  {
    ans = head->next;
    head->next = last;
    last = head;
    head = ans;
  }
  return last;
}

int main(void)
{
  node * head = nullptr;
  head = new(node);
  head->val = 0;
  node * temphead = head;
  for(int i=1;i<1000;i++)//创建/
  {
    node * temp = nullptr;
    temp = new(node);
    temp->val = i;
    temphead->next = temp;
    temphead = temphead->next;
  }
  temphead = revese(head);
  
  while(temphead){
    std::cout<<temphead->val<<std::endl;
    temphead = temphead->next;
  }
  
  while(head){
    temphead = head->next;
    delete head;
    head = temphead;
  }
  return 0;
}
```
