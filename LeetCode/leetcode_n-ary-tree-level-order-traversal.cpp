/*
*
* Tag: BFS
* Time: O(n)
* Space: O(n)
*/
/*
// Definition for a Node.
class Node {
public:
    int val = NULL;
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
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if(root == NULL){
            return ans;
        }
        
        queue<Node *> q;
        q.push(root);
        while(!q.empty()){
            vector<int> curLevel;
            queue<Node *> curQ;
            while(!q.empty()){
                Node *cur = q.front();
                q.pop();
                
                curLevel.push_back(cur->val);
                for(Node *child : cur->children){
                    curQ.push(child);
                }
            }
            
            ans.push_back(curLevel);
            q = curQ;
        }
        
        return ans;
    }
};
