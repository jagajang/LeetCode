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
    map<int, map<int,vector<int>>> column;
    
    void dfs(TreeNode* now, int dep, int col) {
        column[col][dep].push_back(now->val);
        
        if(now->left != NULL)
            dfs(now->left, dep+1, col-1);
        if(now->right != NULL)
            dfs(now->right, dep+1, col+1);
    }
    
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ret;
        
        dfs(root, 0, 0);
        
        for(auto iter = column.begin(); iter != column.end(); iter++) {
            vector<int> tmp;
            for(auto iter2 = iter->second.begin(); iter2 != iter->second.end(); iter2++) {
                sort(iter2->second.begin(), iter2->second.end());
                tmp.insert(tmp.end(), iter2->second.begin(), iter2->second.end());
            }
            ret.push_back(tmp);
        }
        
        return ret;
    }
};