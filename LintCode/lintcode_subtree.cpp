/*
*
* Tag: DFS
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
     * @param T1, T2: The roots of binary tree.
     * @return: True if T2 is a subtree of T1, or false.
     */
    bool isSubtree(TreeNode *T1, TreeNode *T2) {
        // write your code here
        if((T1 && !T2) || (!T1 && !T2))
            return true;
        if(!T1 && T2)
            return false;
        cntt1 = cntt2 = 0;
        cntNode(T2);
        bool isfind = false;
        int cnt = 0;
        check(T1, T2, isfind, cnt);
        return isfind;
    }
    
    void cntNode(TreeNode *T2){
        ++ cntt2;
        if(T2->left)
            cntNode(T2->left);
        if(T2->right)
            cntNode(T2->right);
    }
    
    void check(TreeNode *T1, TreeNode *T2, bool &isfind, int &cnt){
        int lcnt = 0, rcnt = 0;
        if(T1->left)
            check(T1->left, T2, isfind, lcnt);
        if(isfind)
            return ;
        if(T1->right)
            check(T1->right, T2, isfind, rcnt);
        if(isfind)
            return ;
        cnt = lcnt + rcnt + 1;
        if(cnt == cntt2 && T1->val == T2->val){
            isfind = true;
            comp(T1, T2, isfind);
        }
        if(isfind)
            return ;
        return ;
    }
    
    void comp(TreeNode *T1, TreeNode *T2, bool &isfind){
        if(T1->val != T2->val){
            isfind = false;
            return ;
        }
        if(T1->left && T2->left)
            comp(T1->left, T2->left, isfind);
        if((T1->left && !T2->left) || (!T1->left && T2->left)){
            isfind = false;
            return ;
        }
        if(T1->right && T2->right)
            comp(T1->right, T2->right, isfind);
        if((T1->right && !T2->right) || (!T1->right && T2->right)){
            isfind = false;
            return ;
        }
    }

private:
int cntt1, cntt2;
};
