/*
*
* Tag: DFS
* Time: hasNext: O(1); next: O(n)
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
 * Example of iterate a tree:
 * Solution iterator = Solution(root);
 * while (iterator.hasNext()) {
 *    TreeNode * node = iterator.next();
 *    do something for node
 */
class Solution {
public:
    //@param root: The root of binary tree.
    Solution(TreeNode *root) {
        // write your code here
        if(root == NULL)
            return ;
        TreeNode *p = root;
        trace_stack.push(p);
        while(p->left){
            p = p->left;
            trace_stack.push(p);
        }
    }

    //@return: True if there has next node, or false
    bool hasNext() {
        // write your code here
        return !trace_stack.empty();
    }
    
    //@return: return next node
    TreeNode* next() {
        // write your code here
        TreeNode *p = trace_stack.top();
        trace_stack.pop();
        TreeNode *ans = p;
        if(p->right){
            p = p->right;
            trace_stack.push(p);
            while(p->left){
                p = p->left;
                trace_stack.push(p);
            }
        }
        return ans;
    }
    
private:
stack<TreeNode *> trace_stack;

};
