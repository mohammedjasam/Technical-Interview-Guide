/*
*
* Tag: BFS
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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if(root == NULL)
            return ans;
        vector<TreeNode *> cur_q, nxt_q;
        int cfnt = 0, crear = 0, maxval = INT_MIN;
        TreeNode *cur, *nxt;
        cur_q.push_back(root);
        crear = 1;
        while(cfnt < crear){
            maxval = INT_MIN;
            nxt_q.clear();
            while(cfnt < crear){
                cur = cur_q[cfnt ++];
                maxval = max(maxval, cur->val);
                if(cur->left)
                    nxt_q.push_back(cur->left);
                if(cur->right)
                    nxt_q.push_back(cur->right);
            }
            ans.push_back(maxval);
            cur_q = nxt_q;
            cfnt = 0;
            crear = nxt_q.size();
        }
        return ans;
    }
};
