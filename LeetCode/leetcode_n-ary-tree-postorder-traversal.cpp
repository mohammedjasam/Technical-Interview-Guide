/*
*
* Tag: DFS
* Time: O(n)
* Space: O(n)
*/
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> ans;
        dfs(root, ans);
        
        return ans;
    }
    
private:
    void dfs(Node* root, vector<int>& ans){
        if(root == NULL){
            return ;
        }
        
        for(Node *child : root->children){
            dfs(child, ans);
        }        
        ans.push_back(root->val);
    }
};
