/*
*
* Tag: DFS
* Time: O(n)
* Space: O(n)
*/
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
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if(!root){
            return ans;
        }
        
        string tmp_vec = "";
        tmp_vec += to_string(root->val);
        dfs(root, ans, tmp_vec);
        
        return ans;
    }
    
    void dfs(TreeNode* root, vector<string> &ans, string &tmp_vec){
        if(!root->left && !root->right){
            ans.push_back(tmp_vec);
            return ;
        }
        
        if(root->left){
            string nxt_vec = tmp_vec + "->" +to_string(root->left->val);
            dfs(root->left, ans, nxt_vec);
        }
        
        if(root->right){
            string nxt_vec = tmp_vec + "->" +to_string(root->right->val);
            dfs(root->right, ans, nxt_vec);
        }
    }
};
