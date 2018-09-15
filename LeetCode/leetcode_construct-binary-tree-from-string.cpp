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
public:
    TreeNode* str2tree(string s) {
        TreeNode* root = NULL;
        if(s.size() == 0)
            return root;
        int i = 0;
        return createTree(s, i);
    }
private:
    TreeNode* createTree(string &s, int &idx){
        if(idx >= s.size())
            return NULL;
        int num = 0;
        bool isNeg = false;
        if(idx < s.size() && s[idx] == '('){
            ++ idx;
        }
        while(idx < s.size() && (s[idx] == '-' || (s[idx] >= '0' && s[idx] <= '9') )){
            if(s[idx] == '-'){
                isNeg = true;
            }else{
                num = num*10 + (s[idx] - '0');
            }
            ++ idx;
        }
        if(isNeg)
            num = -num;
        TreeNode *p = new TreeNode(num);
        if(s[idx] == ')'){
            ++ idx;
        }else{
            p->left = createTree(s, idx);
            if(s[idx] == '(')
                p->right = createTree(s, idx);
            ++ idx;
        }
        return p;
    }
};
