#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int s=nums.size();
        vector<int> ans;
        for(int i=0;i<s-1;i++)
        {
            for(int j=i+1;j<s;j++)
            {
                if(nums[i]+nums[j]==target)
                {
                    ans.push_back(i);
                    ans.push_back(j);
                    return ans;
                }
            }
        }
    }
};
int main() {
    vector<int> sam;
    int in;
    cin>>in;
    while(in!=-1)
    {
        sam.push_back(in);
        cin>>in;
    }
    cin>>in;
    Solution temp;
    sam=temp.twoSum(sam,in);
    cout<<sam[0]<<" "<<sam[1]<<endl;
    return 0;
}
