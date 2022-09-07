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
    string ret="";
    
    void dfs(TreeNode* now) {
        if(now == NULL)
            return;
        
        string strNow = to_string(now->val);
        ret.insert(ret.end(), strNow.begin(), strNow.end());
        
        if(!now->left && !now->right)
            return;
            
        ret.push_back('(');
        if(now->left)
            dfs(now->left);
        ret.push_back(')');        
        
        if(now->right) {
            ret.push_back('(');
            dfs(now->right);
            ret.push_back(')');            
        }
    }
public:
    string tree2str(TreeNode* root) {
        dfs(root);
        return ret;
    }
};