/*
*
* Tag: DFS
* Time: O(nlgn)
* Space: O(lgn)
*/
/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param A: A sorted (increasing order) array
     * @return: A tree node
     */
    TreeNode *sortedArrayToBST(vector<int> &A) {
        // write your code here
        if(!A.size())
            return NULL;
        int l = 0, r = A.size() - 1;
        return build(A, l, r);
    }
    
    TreeNode *build(vector<int> A, int l, int r){
        if(l == r){
            TreeNode *root = new TreeNode(A[l]);
            return root;
        }else if(l > r)
            return NULL;
        int mid = (l + r)>>1;
        TreeNode *root = new TreeNode(A[mid]);
        root->left = build(A, l, mid - 1);
        root->right = build(A, mid + 1, r);
        return root;
    }
};
