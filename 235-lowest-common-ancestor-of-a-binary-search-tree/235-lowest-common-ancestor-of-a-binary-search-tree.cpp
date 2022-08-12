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
    map < int, pair < int, TreeNode*> > depth;
    
    void setDepth(TreeNode* now, int dep) {
        
        if(now->left != NULL){
            depth[now->left->val] = make_pair(dep + 1, now);
            setDepth(now->left, dep+1);
        }
        
        if(now->right != NULL) {
            depth[now->right->val] = make_pair(dep + 1, now);
            setDepth(now->right, dep+1);
        }
    }
    
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        depth[root->val].first = 0;
        setDepth(root, 0);
        
        if(depth[p->val].first > depth[q->val].first)
            while(depth[p->val].first != depth[q->val].first)
                p = depth[p->val].second;
        else if(depth[p->val] < depth[q->val])
            while(depth[p->val].first != depth[q->val].first)
                q = depth[q->val].second;
        
        while(p->val != q->val) {
            p = depth[p->val].second;
            q = depth[q->val].second;
        }
        
        return p;
    }
};