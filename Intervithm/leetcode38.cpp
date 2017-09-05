#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string ans="";
        if(n==1)
            return "1";
        ans="1";
        for(int i=1;i<n;i++)
        {
            int si=ans.size();
            int count=0;
            string temp="";
            for(int j=0;j<si;j++)
            {

                if(j+1<si&&ans[j]==ans[j+1])
                {
                    count++;
                }
                else if(ans[j]!=ans[j+1])
                {
                    temp=temp+inttostring(++count)+ans[j];
                    count=0;
                }
            }
            ans=temp;
        }
        return ans;
    }
    string inttostring(int i)
    {
            stringstream ss;
            ss<<i;
            return ss.str();
    }
};
int main() {
    int i=0;
    Solution s;
    cin>>i;
    cout<<s.countAndSay(i)<<endl;
    return 0;
}
