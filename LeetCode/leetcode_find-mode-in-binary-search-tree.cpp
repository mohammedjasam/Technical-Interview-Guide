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
    vector<int> findMode(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) {
            return ans;
        }
        
        TreeNode* p = root;
        while(p->right) { 
            p = p->right;
        }
        
        if(p->val < INT_MAX) {
            p->right = new TreeNode(p->val + 1);
        } else {
            p->right = new TreeNode(p->val - 1);
        }
        
        long long cmpval = INT_MIN - 1;
        int cnt = 0, maxcnt = -1;
        dfs(root, cnt, maxcnt, cmpval, ans);
        p->right = NULL;
        
        return ans;
    }
    
private:
    void dfs(TreeNode *root, int &cnt, int &maxcnt, long long &cmpval, vector<int> &ans){
        if(root->left) {
            dfs(root->left, cnt, maxcnt, cmpval, ans);
        }
        
        if(root->val != cmpval){
            if(cnt >= maxcnt){
                if(cnt > maxcnt)
                    ans.clear();
                if(cnt >= maxcnt)
                    ans.push_back(cmpval);
                maxcnt = cnt;
            }
            cnt = 1;
            cmpval = root->val;
        }else{
            ++ cnt;
        }
        
        if(root->right) {
            dfs(root->right, cnt, maxcnt, cmpval, ans);
        }
    }
};
