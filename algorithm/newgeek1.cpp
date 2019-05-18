/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 https://www.nowcoder.com/practice/8a19cbe657394eeaac2f6ea9b0f6fcf6?tpId=13&tqId=11157&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking
 */
class Solution {
public:
    TreeNode* digui(vector<int> pre,vector<int> vin,int pleft,int pright,int vleft,int vright){
        TreeNode* ans=NULL;
        
        if(pleft<pright)
        {
            for (int i=vleft;i<vright;i++)
            {
                if (vin[i]==pre[pleft])
                {
                    int distance=i-vleft;
                    ans =new TreeNode(pre[pleft]);
                    ans->left=digui(pre,vin,pleft+1,pleft+distance+1,vleft,i);
                    ans->right=digui(pre,vin,pleft+distance+1,pright,vleft+distance+1,vright);
                    break;
                }
            }
        }
        return ans;
    }
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        int arrayLen=pre.size();
        TreeNode* ans=digui(pre,vin,0,arrayLen,0,arrayLen);
        return ans;
    }
};
