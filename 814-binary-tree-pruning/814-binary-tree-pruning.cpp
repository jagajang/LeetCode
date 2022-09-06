/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    bool hasOne(TreeNode* now) {
        if(now == NULL)
            return false;

        int ret = false;
        if(hasOne(now->left))
            ret = true;
        else
            now->left = NULL;
        
        if(hasOne(now->right))
            ret = true;
        else
            now->right = NULL;
        
        return now->val || ret;
    }
    
public:
    TreeNode* pruneTree(TreeNode* root) {
        if(hasOne(root))
            return root;
        else
            return NULL;
    }
};