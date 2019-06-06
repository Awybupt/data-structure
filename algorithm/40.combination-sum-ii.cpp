/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 */
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> path;
        dfs(candidates,0, target,path,ans);
        return ans;
    }

    void dfs(vector<int>& condidates, int cursor, int target,vector<int>& path,vector<vector<int>>& ans)
    {
        if (target ==0)
        {
            ans.push_back(path);
            return ;
        }
        if (target < 0)
            return ;
        for (int i=cursor;i<condidates.size();i++)
        {
            if (condidates[i]>target) return ;
            if (i>cursor&&condidates[i]==condidates[i+1])
                continue;
            path.push_back(condidates[i]);
            dfs(condidates,i+1, target-condidates[i],path,ans);
            path.pop_back(condidates[i]);

        }
    }
};

