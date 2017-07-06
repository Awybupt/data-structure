#include <iostream>
#define siz 100
using namespace std;
struct stak{
    char *top;
    char *base;
};
struct que{
    char *base;
    char *top;
};
int main()
{
    struct stak s;
    struct que q;
    (s.base)=new char[siz];
    s.top=s.base;
    (q.base)=new char[siz];
    q.top=q.base;
    char bbs;
    cin>>bbs;
    while(bbs!='#')
    {
            *(s.top)=bbs;
            ++s.top;
            *(q.top)=bbs;
            ++q.top;
         cin>>bbs;
    }
    s.top--;
    q.top--;
    while(q.top!=q.base)
    {
        if((*s.top)!=(*q.base))
        {
            delete(s.top);
            delete(q.top);
            cout << "False!" << endl;
            return 0;
            q.base++;
        }
        else
        {
            q.base++;
            s.top--;
        }
    }
    delete(s.top);
    delete(q.top);
    cout << "true!" << endl;
    return 0;
}
