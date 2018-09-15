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
     * @aaram a, b, the root of binary trees.
     * @return true if they are identical, or false.
     */
    bool isIdentical(TreeNode* a, TreeNode* b) {
        // Write your code here
        if(!a && !b)
            return true;
        if((!a && b) || (a && !b))
            return false;
        queue<TreeNode *> qa, qb;
        qa.push(a);
        qb.push(b);
        while(!qa.empty()){
            TreeNode *cura = qa.front(), *curb = qb.front();
            qa.pop();
            qb.pop();
            if(cura->val != curb->val)
                return false;
            if((cura->left && !curb->left) || (!cura->left && curb->left))
                return false;
            if(cura->left)
                qa.push(cura->left);
            if(curb->left)
                qb.push(curb->left);
            if((cura->right && !curb->right) || (!cura->right && curb->right))
                return false;
            if(cura->right)
                qa.push(cura->right);
            if(curb->right)
                qb.push(curb->right);
        }
        return true;
    }
};
