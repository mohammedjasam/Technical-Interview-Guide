/*
*
* Tag: DFS
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
private:
    int ans;
public:
    int longestUnivaluePath(TreeNode* root) {
        ans = 0;
        if(!root){
            return ans;
        }
        
        getLongestUnivaluePath(root);
        
        return ans;
    }

private:
    int getLongestUnivaluePath(TreeNode *root){
        int longestUnivalPathOfRoot = 0;
        int longestUnivalPathReturned = 0;
        if(root->left){
            int longestUnivalPathOfLeftChild = getLongestUnivaluePath(root->left);
            if(root->left->val == root->val){
                longestUnivalPathOfRoot += longestUnivalPathOfLeftChild + 1;
                longestUnivalPathReturned = max(longestUnivalPathReturned, longestUnivalPathOfLeftChild + 1);
            }
        }
        
        if(root->right){
            int longestUnivalPathOfRightChild = getLongestUnivaluePath(root->right);
            if(root->right->val == root->val){
                longestUnivalPathOfRoot += longestUnivalPathOfRightChild + 1;
                longestUnivalPathReturned = max(longestUnivalPathReturned, longestUnivalPathOfRightChild + 1);
            }
        }
        
        ans = max(ans, longestUnivalPathOfRoot);
        return longestUnivalPathReturned;
    }
};
