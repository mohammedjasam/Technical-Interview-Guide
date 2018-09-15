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
     * @param root the root of the binary tree
     * @return all root-to-leaf paths
     */
    vector<string> binaryTreePaths(TreeNode* root) {
        // Write your code here
        vector<string> ans;
        if(!root)
            return ans;
        string val = "";
        dfs(root, ans, val, 0);
        return ans;
    }
private:
    void dfs(TreeNode *root, vector<string> &ans, string val, int dep){
        if(dep)
            val += "->";
        val += getIntToString(root->val);
        if(!root->left && !root->right){
            ans.push_back(val);
            return ;
        }
        if(root->left)
            dfs(root->left, ans, val, dep + 1);
        if(root->right)
            dfs(root->right, ans, val, dep + 1);
    }
    
    string getIntToString(int num){
        string res;
        stringstream convert;
        convert << num;
        res = convert.str();
        return res;
    }
    
};
