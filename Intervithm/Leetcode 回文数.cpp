#include <iostream>
#include <vector>
class solution{
public:
    bool ispalind(int s){
        int t=s,an=0,i=0;
        for(;t>0;t/=10)
        {
            an=10*an+t%10;
            ++i;
        }
        /*for(int j;j<i/2;j++)
        {
            if(s%10!=an%10)
                return false;
        }
        return true;
        */
        if(an==s)
            return true;
        return false;
    }
};
int main(void)
{
    solution ans;
    int num=0;
    std::cin>>num;
    std::cout<<ans.ispalind(num);
    return 0;
}
