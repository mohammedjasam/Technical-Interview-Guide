/*
*
* Tag: Data Structure (Hash)
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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> ans;
        if(root == NULL)
            return ans;
        unordered_map<int,int> cnt_dict;
        cnt_dict.clear();
        int sum = 0, maxcnt = 0, cnt = 0;;
        dfs(root, cnt_dict, sum, maxcnt, cnt);
        unordered_map<int,int>::iterator it;
        ans.resize(cnt);
        int i = 0;
        for(it = cnt_dict.begin(); it != cnt_dict.end() && i < cnt; ++ it){
            if(it->second == maxcnt){
                ans[i ++] = it->first;
            }
        }
        return ans;
    }
    
private:
    void dfs(TreeNode* root, unordered_map<int,int> &cnt_dict, int &sum, int &maxcnt, int &cnt){
        int left_sum = 0, right_sum = 0;
        if(root->left)
            dfs(root->left, cnt_dict, left_sum, maxcnt, cnt);
        if(root->right)
            dfs(root->right, cnt_dict, right_sum, maxcnt, cnt);
        sum = root->val + left_sum + right_sum;
        ++ cnt_dict[sum];
        if(cnt_dict[sum] > maxcnt){
            cnt = 1;
            maxcnt = cnt_dict[sum];
        }else if(cnt_dict[sum] == maxcnt)
            ++ cnt;
    }
};
