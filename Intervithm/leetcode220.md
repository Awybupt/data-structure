## Contains Duplicate III

* Given an array of integers, find out whether there are two distinct indices i and j in the array such that the absolute difference between nums[i] and nums[j] is at most t and the absolute difference between i and j is at most k.

```
Example 1:

Input: nums = [1,2,3,1], k = 3, t = 0
Output: true
Example 2:

Input: nums = [1,0,1,1], k = 1, t = 2
Output: true
Example 3:

Input: nums = [1,5,9,1,5,9], k = 2, t = 3
Output: false
```

```cpp
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        vector<long int> Nums;
        for(int i = 0; i < nums.size(); i++)
            Nums.push_back(nums[i]);
        multiset <long int> st;
        for(int i = 0; i < Nums.size(); i++)
        {
            if(i > k) st.erase(st.find(Nums[i-k-1]));
            auto it = st.lower_bound(Nums[i]-t);
            if(it!=st.end())
                if( *it-Nums[i]>=-t && *it-Nums[i]<=t)
                    return true;
            st.insert(Nums[i]);
        }
        return false;
    }
};
```
