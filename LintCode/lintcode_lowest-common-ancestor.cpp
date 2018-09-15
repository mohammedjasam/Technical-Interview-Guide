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
     * @param root: The root of the binary search tree.
     * @param A and B: two nodes in a Binary.
     * @return: Return the least common ancestor(LCA) of the two nodes.
     */
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *A, TreeNode *B) {
        // write your code here
        if(!root)
            return NULL;
        unordered_map<TreeNode *,int> lv;
        unordered_map<TreeNode *, TreeNode *> fa;
        vector<TreeNode *> q;
        int lvcnt = 0;
        int front = 0, rear = 0, lv_rear = 0;
        q.push_back(root);
        ++ rear;
        ++ lv_rear;
        fa[root] = NULL;
        while(front < rear){
            ++ lvcnt;
            while(front < rear){
                TreeNode *p = q[front ++];
                lv[p] = lvcnt;
                if(p->left){
                    q.push_back(p->left);
                    ++ lv_rear;
                    fa[p->left] = p;
                }
                if(p->right){
                    q.push_back(p->right);
                    ++ lv_rear;
                    fa[p->right] = p;
                }
            }
            front = rear;
            rear = lv_rear;
        }
        
        if(lv.find(A) == lv.end() || lv.find(B) == lv.end())
            return NULL;
            
        if(lv[A] < lv[B])
            swap(A, B);
        
        while(lv[A] > lv[B]) A = fa[A];
        while(A != B){
            A = fa[A];
            B = fa[B];
        }
        return A;
    }
};
