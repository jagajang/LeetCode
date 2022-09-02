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

struct NodeInfo {
    int num = 0;
    long long sum = 0;
    
    NodeInfo(int num, int sum) {
        this->num = num;
        this->sum = sum;
    }
};

class Solution {
private:
    vector<NodeInfo> depInfo = vector<NodeInfo>();
    
    void dfs(TreeNode* now, int depth) {
        if(depth == this->depInfo.size())
            this->depInfo.push_back(NodeInfo(1, now->val));
        else {
            this->depInfo[depth].num++;
            this->depInfo[depth].sum += now->val;
        }
        
        if(now->left)
            dfs(now->left, depth+1);
        if(now->right)
            dfs(now->right, depth+1);
    }
public:
    vector<double> averageOfLevels(TreeNode* root) {
        dfs(root, 0);
        
        vector<double> ret = vector<double>(depInfo.size(), 0);
        for(int i = 0; i < depInfo.size(); i++)
            ret[i] = 1.0 * depInfo[i].sum / depInfo[i].num;
        return ret;
    }
};