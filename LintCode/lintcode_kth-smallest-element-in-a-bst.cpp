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
private:
    bool isKthSmallestElementFound;
    int kthSmallestElement;
    int rank;
public:
    /**
     * @param root: the given BST
     * @param k: the given k
     * @return: the kth smallest element in BST
     */
    int kthSmallest(TreeNode * root, int k) {
        init();
        
        dfs(root, k);
        
        return kthSmallestElement;
    }
private:
    void init(){
        isKthSmallestElementFound = false;
        rank = 0;
    }
    
    void dfs(TreeNode * root, int k){
        if(isKthSmallestElementFound)
            return ;
        if(root->left)
            dfs(root->left, k);
        
        ++ rank;
        if(rank == k){
            kthSmallestElement = root->val;
            isKthSmallestElementFound = true;
            return ;
        }
        
        if(root->right)
            dfs(root->right, k);
    }
};
