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
    int findSecondMinimumValue(TreeNode* root) {
        if(root == NULL){
            return -1;
        }
        
        queue<TreeNode *> q;
        q.push(root);
        
        set<int> existingValues;
        while(!q.empty()){
            TreeNode * curNode = q.front();
            q.pop();
                        
            existingValues.insert(curNode->val);
            if(curNode->left != NULL){
                q.push(curNode->left);
                q.push(curNode->right);
            }
        }
        
        return existingValues.size() < 2 ? -1 : getSecondSmallestValueOf(existingValues);
    }
private:
    int getSecondSmallestValueOf(set<int> &valueSet){
        auto it = valueSet.begin();
        ++ it;
        return *it;
    }
};
