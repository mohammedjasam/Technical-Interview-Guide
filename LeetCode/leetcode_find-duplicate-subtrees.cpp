/*
*
* Tag: DFS
* Time: O(n^2)
* Space: O(n^2)
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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> ans;
        unordered_map<string,int> serializedBST;
        dfs(root, serializedBST, ans);
        return ans;
    }
private:
    string dfs(TreeNode* root, unordered_map<string,int> &serializedBST, vector<TreeNode*> &ans){
        if(root == NULL){
            return "#";
        }
        
        string serializedValue =  dfs(root->left, serializedBST, ans) + "," + dfs(root->right, serializedBST, ans) + "," + to_string(root->val);
        if(serializedBST[serializedValue] == 1){
            ans.push_back(root);
        }
        ++ serializedBST[serializedValue];
        
        return serializedValue;
    }
};
