/*
*
* Tag: DFS + BFS
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
    int findClosestLeaf(TreeNode* root, int k) {
        if(root->left == NULL && root->right == NULL) {
            return k;
        }
        
        int shortestDistance = INT_MAX;
        int ans = 0;
        vector<TreeNode *> nodesInPathFromRootToNodeK;
        findAllNodesInPathFromRootToNodeK(root, k, nodesInPathFromRootToNodeK);
        
        TreeNode *nodeK = nodesInPathFromRootToNodeK[ nodesInPathFromRootToNodeK.size() - 1 ];
        if(nodeK->left == NULL && nodeK->right == NULL) {
            return k;
        }
        
        unordered_set<TreeNode *> nodesIgnoredInSearch(nodesInPathFromRootToNodeK.begin(), nodesInPathFromRootToNodeK.end());
        for(int i = 0; i < nodesInPathFromRootToNodeK.size(); ++ i){
            int additionalDistance = nodesInPathFromRootToNodeK.size() - i - 1;
            pair<int, TreeNode*> distanceOfClosestLeaf = getClosestLeafFromNode(nodesInPathFromRootToNodeK[i], nodesIgnoredInSearch);
            
            if(distanceOfClosestLeaf.second == NULL){
                continue;
            }
            
            int actualShortestDistance = distanceOfClosestLeaf.first + additionalDistance;
            if(actualShortestDistance < shortestDistance) {
                shortestDistance = actualShortestDistance;
                ans = distanceOfClosestLeaf.second->val;
            }
        }
        
        return ans;
    }
private:
    void findAllNodesInPathFromRootToNodeK(TreeNode* root, int k, vector<TreeNode *> &nodesInPathFromRootToNodeK){
        nodesInPathFromRootToNodeK.push_back(root);
        if(root->val == k){
            return ;
        }
        
        TreeNode *lastVisitedNode = nodesInPathFromRootToNodeK[ nodesInPathFromRootToNodeK.size() - 1 ];
        if(root->left != NULL){
            findAllNodesInPathFromRootToNodeK(root->left, k, nodesInPathFromRootToNodeK);
        }
        
        lastVisitedNode = nodesInPathFromRootToNodeK[ nodesInPathFromRootToNodeK.size() - 1 ];
        if(lastVisitedNode->val == k){
            return ;
        }
        
        if(root->right != NULL){
            findAllNodesInPathFromRootToNodeK(root->right, k, nodesInPathFromRootToNodeK);
        }
        
        lastVisitedNode = nodesInPathFromRootToNodeK[ nodesInPathFromRootToNodeK.size() - 1 ];
        if(lastVisitedNode->val == k){
            return ;
        }
        
        nodesInPathFromRootToNodeK.pop_back();
    }
    
    pair<int, TreeNode*> getClosestLeafFromNode(TreeNode *root, unordered_set<TreeNode *> &nodesIgnoredInSearch){
        queue<pair<int, TreeNode*>> q;
        q.push(make_pair(0, root));
        
        nodesIgnoredInSearch.erase(root);
        
        TreeNode* dummyLeafNode = NULL;
        pair<int, TreeNode *> ans = make_pair(-1, dummyLeafNode);
        while(!q.empty()){
            pair<int, TreeNode*> curNode = q.front();
            q.pop();
            TreeNode *node = curNode.second;
            if(node->left == NULL && node->right == NULL){
                ans = curNode;
                break;
            }
            
            if(nodesIgnoredInSearch.count(node) != 0){
                continue;
            }
            
            int curDistance = curNode.first + 1;
            if(node->left != NULL) {
                q.push(make_pair(curDistance, node->left));
            }
            if(node->right != NULL) {
                q.push(make_pair(curDistance, node->right));
            }
        }
        
        nodesIgnoredInSearch.insert(root);
        
        return ans;
    }
};
