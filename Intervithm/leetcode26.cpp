#include <iostream>
#include <vector>
using namespace std;
/*
 * public class Solution {
    public int removeDuplicates(int[] nums) {
        if(nums.length == 0) return 0;
        int dup = nums[0];
        int end = 1;
        for(int i = 1; i < nums.length; i++){
            if(nums[i]!=dup){
                nums[end] = nums[i];
                dup = nums[i];
                end++;
            }
        }
        return end;
    }
}
 * */

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int temp=nums.size();
        if(temp==0)
            return 0;
        int longth=1;
        for(int i=1;i<temp;i++)
        {
            if(nums[i-1]!=nums[i])
            {
                nums[longth]=nums[i];//血的教训在这里
                ++longth;
            }
        }
        return longth;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
