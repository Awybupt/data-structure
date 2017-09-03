#include <iostream>
#include <vector>

using namespace std;
/**
 * public class Solution {
    public int removeElement(int[] A, int elem) {
        if (A.length ==0) return A.length;
        int i = 0, j = A.length - 1;
        while (i <= j) {
            if (A[i] == elem) {
                int tmp = A[i];
                A[i] = A[j];
                A[j] = tmp;
                --j;
            } else {
                ++i;
            }
        }
        //return j; 因为while (i<=j)才结束，而不是while (i < j)才结束，所以这里返回j+1
        return j + 1;
    }
}
 *
 *
 * class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != val) nums[res++] = nums[i];
        }
        return res;
    }
};
 差距
 */
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int leng=nums.size();

        if(leng==0)
            return 0;
        for(leng;leng>=0;leng--)
            if(nums[leng-1]!=val)
                break;
        for(int i=0;i<leng;i++)
        {
            if(nums[i]==val)
            {
                for(int j=leng-1;j>i-1;j--)
                {
                    if(nums[j]!=val)
                    {
                        nums[i]=nums[j];
                        nums[j]=val;
                        --leng;
                        break;
                    }
                }
            }
        }
        return leng;
    }
};
int main() {
    vector<int> inpu;
    int valu;
    cin>>valu;
    while(valu!=-1)
    {
        inpu.push_back(valu);
        cin>>valu;
    }
    cin>>valu;
    Solution sol;
    int ans=sol.removeElement(inpu,valu);
    for(int i=0;i<ans;i++)
    {
        cout<<inpu[i];
    }
    return 0;
}
