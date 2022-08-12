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
private:
    TreeNode *p, *q;
    pair < int, TreeNode* > getLCA(TreeNode* now) {
        int retInt = 0;
        TreeNode* nptr = NULL;
        
        if(now == NULL)
            return make_pair(0, nptr);
        
        pair < int, TreeNode* > left = getLCA(now->left);
        pair < int, TreeNode* > right = getLCA(now->right);
            
        // completed
        if(left.first == 3)
            return left;
        else if(right.first == 3)
            return right;
        
        // p or q
        if(now == p)
            retInt = 1;
        else if(now == q)
            retInt = 2;
        
        // complete
        retInt |= left.first | right.first;
        if(retInt == 3)
            return make_pair(3, now);
        
        // not complete
        return make_pair(retInt, nptr);
    }
    
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        this->p = p;
        this->q = q;
        
        return getLCA(root).second;
    }
};