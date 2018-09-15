/*
*
* Tag: DFS
* Time: O(n)
* Space: O(n)
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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return build(num, 0, num.size() - 1);
    }
    
    TreeNode *build(vector<int> &num,int l,int r){
        if(l > r) return NULL;
        int mid = (l + r) >> 1;
        TreeNode *root = new TreeNode(num[mid]);
        root->left = build(num,l,mid - 1);
        root->right = build(num, mid + 1,r);
        return root;
    }
};
