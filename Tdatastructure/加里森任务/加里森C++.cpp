#include <iostream>

using namespace std;
typedef struct soldier
{
    int nnum;
    struct soldier* next;
}soldier,*linklist;
int main()
{
    int n,x,y;//n必须大于等于2
    cout<<"please input the number of the soldier."<<endl;
    cin>>n;
        linklist headptr,p;
        soldier *linshi;
    int a=1;
    headptr=NULL;

    for(a;a<n;a++)
    {
        p->nnum=a;
        if(headptr==NULL)
            headptr=p;
        p->next=new soldier;
        p=p->next;
    }
    p->nnum=n;
    p->next=headptr;
    p=headptr->next;
    cout<<"please input y and x,means from x ,every y"<<endl;
    cin>>x;
    cin>>y;
    do
    {
        if(p->nnum==x)
            break;
        p=p->next;
    }
    while(p!=headptr);
    int c=0;
    p=headptr;
    while(p->next!=p)
    {
        p=p->next;
        c++;
        if(c==y)
        {
            linshi=p->next;

            p->next=p->next->next;
            cout<<linshi->nnum<<" ";
            delete linshi;
            c=0;
        }
    }
    cout<<p->nnum;
    if(p==headptr)
        cout<<"  True!"<<endl;
        else{
            cout<<"  False!"<<endl;
        }
    delete p;
    return 0;
}
