/*
*
* Tag: BFS
* Time: O(n)
* Space: O(n)
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        int ans = 0;
        if(root == NULL) {
            return ans;
        }
        
        queue<pair<TreeNode *, int>> currentLevel;
        currentLevel.push(make_pair(root,1));
        while(!currentLevel.empty()){
            queue<pair<TreeNode *, int>> nextLevel;
            int leftBoundNumber = -1, rightBoundNumber = -1;
            while(!currentLevel.empty()){
                pair<TreeNode*,int> node = currentLevel.front();
                currentLevel.pop();
                
                if(node.first->left != NULL) {
                    nextLevel.push(make_pair(node.first->left, node.second*2));
                }
                
                if(node.first->right != NULL) {
                    nextLevel.push(make_pair(node.first->right, node.second*2 + 1));
                }
                
                if(leftBoundNumber == -1) {
                    leftBoundNumber = node.second;
                } 
                rightBoundNumber = node.second;
            }
            
            currentLevel = nextLevel;
            ans = max(ans, rightBoundNumber - leftBoundNumber + 1);
        }
        
        return ans;
    }
};
