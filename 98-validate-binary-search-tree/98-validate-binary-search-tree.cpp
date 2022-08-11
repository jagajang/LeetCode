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
    bool isValid(TreeNode* now, long long min, long long max) {
        if(now == NULL)
            return true;
        
        if( now->val < min
           || now->val > max
           || (now->left != NULL && now->left->val >= now->val)
           || (now->right != NULL && now->right->val <= now->val)
           )
            return false;
        
        return isValid(now->left, min, now->val - 1LL) && isValid(now->right, now->val + 1LL, max);
    }
public:
    bool isValidBST(TreeNode* root) {
        return isValid(root, INT_MIN, INT_MAX);
    }
};