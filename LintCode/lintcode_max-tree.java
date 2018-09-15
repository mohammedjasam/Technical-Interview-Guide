/*
*
* Tag: Data Structure (Stack)
* Time: ?
* Space: ?
*/
/**
 * Definition of TreeNode:
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left, right;
 *     public TreeNode(int val) {
 *         this.val = val;
 *         this.left = this.right = null;
 *     }
 * }
 */
public class Solution {
    /**
     * @param A: Given an integer array with no duplicates.
     * @return: The root of max tree.
     */
    public TreeNode maxTree(int[] A) {
        // write your code here
        Stack<TreeNode> stack = new Stack<TreeNode>();//decreasing stack
        for (int i = 0; i < A.length; i++) {
            TreeNode newNode = new TreeNode(A[i]);
            TreeNode pre = null;
            while (!stack.isEmpty() && stack.peek().val < A[i]) {
                TreeNode cur = stack.pop();
                if (pre != null) {
                    cur.right = pre;
                }
                pre = cur;
                newNode.left = pre;
            }
            stack.push(newNode);
        }
        TreeNode preNode = null;
        while (!stack.isEmpty()) {
            TreeNode curNode = stack.pop();
            curNode.right = preNode;
            preNode = curNode;
        }
        return preNode;
    }
}
