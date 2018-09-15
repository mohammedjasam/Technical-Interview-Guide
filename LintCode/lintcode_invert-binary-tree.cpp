/*
*
* Tag: BFS
* Time: O(n)
* Space: O(n)
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
     * @param root: a TreeNode, the root of the binary tree
     * @return: nothing
     */
    void invertBinaryTree(TreeNode *root) {
        // write your code here
        if(!root)
            return ;
        int h = 0;
        vector<TreeNode* > q_fst, q_snd;
        q_fst.push_back(root);
        int f_st = 0, r_st = 1, f_nd = 0, r_nd = 0;
        while(f_st < r_st){
            q_snd.resize(0);
            f_nd = r_nd = 0;
            while(f_st < r_st){
                TreeNode *tmp = q_fst[f_st ++];
                swap(tmp->left, tmp->right);
                if(tmp->left){
                    q_snd.push_back(tmp->left);
                    ++ r_nd;
                }
                if(tmp->right){
                    q_snd.push_back(tmp->right);
                    ++ r_nd;
                }
            }
            q_fst.resize(r_nd);
            f_st = r_st = 0;
            while(f_nd < r_nd){
                q_fst[f_nd] = q_snd[f_nd];
                ++ f_nd;
                ++ r_st;
            }
        }
        return ;
    }
};
