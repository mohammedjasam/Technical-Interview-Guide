/*
*
* Tag: DFS + BFS
* Time: O(mn)
* Space: O(m+n)
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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(s == NULL && t == NULL){
            return true;
        }
        
        if((s == NULL && t != NULL) || (s != NULL && t == NULL)){
            return false;
        }
        
        bool isSubtreeFound = false;
        if(s->val == t->val){
            isSubtreeFound = checkSubstreeEquality(s, t);
        }
        
        return isSubtreeFound ? isSubtreeFound : (isSubtree(s->left, t) || isSubtree(s->right, t));
    }
    
private:
    bool checkSubstreeEquality(TreeNode* s, TreeNode* t){
        queue<TreeNode *> queueForS, queueForT;
        queueForS.push(s);
        queueForT.push(t);
        
        while(!queueForT.empty()){
            TreeNode *curNodeFromS = queueForS.front();
            queueForS.pop();
            TreeNode *curNodeFromT = queueForT.front();
            queueForT.pop();
            
            if(!areTreeNodesEqual(curNodeFromS, curNodeFromT)){
                return false;
            }
            
            if(curNodeFromS->left != NULL){
                queueForS.push(curNodeFromS->left);
                queueForT.push(curNodeFromT->left);
            }
            
            if(curNodeFromS->right != NULL){
                queueForS.push(curNodeFromS->right);
                queueForT.push(curNodeFromT->right);
            }
        }
        
        return true;
    }
    
    bool areTreeNodesEqual(TreeNode* curNodeFromS, TreeNode* curNodeFromT){
        return curNodeFromS->val == curNodeFromT->val && 
            ( (curNodeFromS->left == NULL && curNodeFromT->left == NULL) || (curNodeFromS->left != NULL && curNodeFromT->left != NULL) ) && 
            ( (curNodeFromS->right == NULL && curNodeFromT->right == NULL) || (curNodeFromS->right != NULL && curNodeFromT->right != NULL) );
    }
};
