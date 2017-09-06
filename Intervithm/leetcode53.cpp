#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len=nums.size();
        int b[len+1];
        for(int i=0;i<len+1;i++)
            b[i]=0;
        int max=INT_MIN;
        for(int i=1;i<=len;i++)
        {
            if(b[i-1]>0)
            {
                b[i]=b[i-1]+nums[i-1];
            }
            else
            {
                b[i]=nums[i-1];
            }
            if(b[i]>max)
                max=b[i];
        }
        return max;
    }
};
int main() {
    vector<int> simple;
    int num;
    cin>>num;
    while(num!=-10)
    {
        simple.push_back(num);
        cin>>num;
    }
    Solution s;
    cout<<s.maxSubArray(simple)<<endl;
    return 0;
}
