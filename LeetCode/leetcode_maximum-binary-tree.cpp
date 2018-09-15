/*
*
* Tag: DFS
* Time: O(n^2)
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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return nums.size() == 0? NULL : buildMaximumBinaryTree(nums, 0, nums.size());
    }
private:
    TreeNode* buildMaximumBinaryTree(vector<int>& nums, int startIndex, int endIndex){
        if(startIndex == endIndex){
            return NULL;
        }
        
        int indexOfMaxValue = getIndexOfMaxValue(nums, startIndex, endIndex);
        TreeNode* root = new TreeNode(nums[indexOfMaxValue]);
        root->left = buildMaximumBinaryTree(nums, startIndex, indexOfMaxValue);
        root->right = buildMaximumBinaryTree(nums, indexOfMaxValue + 1, endIndex);
        
        return root;
    }
    
    int getIndexOfMaxValue(vector<int>& nums, int startIndex, int endIndex){
        int maxValue = nums[startIndex];
        int indexOfMaxValue = startIndex;
        
        for(int i = startIndex; i < endIndex; ++ i){
            if(maxValue < nums[i]){
                maxValue = nums[i];
                indexOfMaxValue = i;
            }
        }
        
        return indexOfMaxValue;
    }
};
