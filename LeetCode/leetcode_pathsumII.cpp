/*
* Algorithm: DFS
* Time complexity: O(n)
* Memory complexity: O(n)
*/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<vector<int> > ans;
        if(root == NULL) return ans;
        int tmp_sum = root -> val;
        vector<int> path;
        path.push_back(tmp_sum);
        if(tmp_sum == sum && root -> left == NULL && root -> right == NULL){
            ans.push_back(path);
            return ans;
        }
        if(root->left != NULL){
            dfs(root->left,tmp_sum,sum,path,ans);
        }
        if(root->right!=NULL){
            dfs(root->right,tmp_sum,sum,path,ans);
        }
        return ans;
    }
    
    void dfs(TreeNode *p,int tmp_sum,int sum,vector<int> path,vector<vector<int> > &ans){
        tmp_sum += p->val;
        path.push_back(p->val);
        if(p->left == NULL && p->right == NULL){
            if(tmp_sum == sum) ans.push_back(path);
            return ;
        }
        if(p->left != NULL){
            dfs(p->left,tmp_sum,sum,path,ans);
        }
        if(p->right!=NULL){
            dfs(p->right,tmp_sum,sum,path,ans);
        }
    }
};
