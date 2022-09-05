/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
private:
    vector<vector<int>> ret;
    
    void dfs(Node* now, int dep) {
        if(now == NULL)
            return;
        if(dep == ret.size())
            ret.push_back(vector<int>());
        
        ret[dep].push_back(now->val);
        
        for(int i = 0; i < now->children.size(); i++)
            dfs(now->children[i], dep+1);
    }
public:
    vector<vector<int>> levelOrder(Node* root) {
        dfs(root, 0);
        return ret;
    }
};