#include <iostream>

#include <string>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int leth=str.length();
        if(leth==0)
            return 0;

        bool nagetive=false;
        int i=0;
        for(i;i<leth&&str[i]==' ';i++);
        if(str[i]=='-')
        {
            nagetive=true;
            i++;
        }
        else if(str[i]=='+')
             i++;

        int res=0;
        while(i<leth)
        {
            int digit=str[i]-'0';
            if(digit<0||digit>9)
                break;
            res=res*10+digit;
            i++;
        }

        if(res>INT_MAX)
        {
            if(nagetive==false)
                return INT_MAX;
            else
                return -INT_MIN;
        }
        else if(nagetive==false)
            return res;
        else
            return 0-res;
    }
};

int main(void) {
    string inp;
    cin>>inp;
    Solution temp;
    cout<<temp.myAtoi(inp)<<endl;
    return 0;
}
