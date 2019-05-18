## Binary Tree Paths

* Given a binary tree, return all root-to-leaf paths.

> Note: A leaf is a node with no children.

```
Example:

Input:

   1
 /   \
2     3
 \
  5

Output: ["1->2->5", "1->3"]

Explanation: All root-to-leaf paths are: 1->2->5, 1->3
```

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (root) 
            view(root, "", res);
        return res;
    }
    void view(TreeNode* node, string out, vector<string>& res) {
        if (!node->left && !node->right) 
            res.push_back(out + to_string(node->val));
        if (node->left) 
            view(node->left, out + to_string(node->val) + "->", res);
        if (node->right) 
            view(node->right, out + to_string(node->val) + "->", res);
    }
};
```
