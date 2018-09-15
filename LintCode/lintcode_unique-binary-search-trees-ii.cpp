/*
*
* Tag: DFS
* Time: ?
* Space: ?
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
     * @paramn n: An integer
     * @return: A list of root
     */
    vector<TreeNode *> generateTrees(int n) {
        // write your code here
        if(n == 0)
            return generate(1, 0);
        else
            return generate(1, n);
    }
private:
    vector<TreeNode *> generate(int sta, int end){
        vector<TreeNode *> subTree;
        if(sta > end){
            subTree.push_back(NULL);
            return subTree;
        }
        
        for(int k = sta; k <= end; k ++){
            vector<TreeNode *> leftSubTree = generate(sta, k - 1);
            vector<TreeNode *> rightSubTree = generate(k + 1, end);
            for(auto i : leftSubTree){
                for(auto j : rightSubTree){
                    TreeNode *node = new TreeNode(k);
                    node->left = i;
                    node->right = j;
                    subTree.push_back(node);
                }
            }
        }
        return subTree;
    }
};
