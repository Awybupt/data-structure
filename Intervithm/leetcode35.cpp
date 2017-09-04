#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
//        int a=nums.size(),i=0;//没用二分搜索
//        if(a==0)
//            return 0;
//        for(i;i<a&&nums[i]<target;i++) ;
//        if(i==a)
//            return a;
//        else
//            return i;
        int low=0,high=nums.size();//二分搜索
        while(low<high)
        {
            int mid=(high+low)/2;
            if(nums[mid]>=target)
                high=mid;
            else
                low=mid+1;
        }
        return low;
    }
};

int main() {
    vector<int> sam;
    int tar;
    cin>>tar;
    while(tar!=-1)
    {
        sam.push_back(tar);
        cin>>tar;
    }
    cin>>tar;
    Solution s;
    cout<<s.searchInsert(sam,tar)<<endl;
    return 0;
}
