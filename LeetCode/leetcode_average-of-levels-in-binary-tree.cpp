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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        if(root == NULL){
            return ans;
        }
        
        queue<TreeNode *> curLevel;
        curLevel.push(root);
        while(!curLevel.empty()){
            queue<TreeNode *> nextLevel;
            long long sum = 0; 
            int numOfNodes = curLevel.size();
            while(!curLevel.empty()){
                TreeNode *node = curLevel.front();
                curLevel.pop();
                sum += node->val;
                if(node->left){
                    nextLevel.push(node->left);
                }
                if(node->right){
                    nextLevel.push(node->right);
                }
            }
            curLevel = nextLevel;
            double avg = (double)sum/(double)numOfNodes;
            ans.push_back(avg);
        }
        
        return ans;
    }
};
