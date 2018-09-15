/*
*
* Tag: Binary Search Tree (Data Structure)
* Time: O(n)
* Space: O(n)
*/
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class SummaryRanges {
private:
struct TreeNode {
     int lbnd, rbnd;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int lval, int rval) : lbnd(lval), rbnd(rval), left(NULL), right(NULL) {}
};

public:
    /** Initialize your data structure here. */
    SummaryRanges() {
        root = NULL;
    }
    
    void addNum(int val) {
        if(!root){
            root = new TreeNode(val, val);
            return ;
        }
        solve(val, root);
    }
    
    vector<Interval> getIntervals() {
        vector<Interval> ans;
        dfs(root, ans);
        return ans;
    }
private:
    void solve(int val, TreeNode *root){
        if(root->lbnd <= val && val <= root->rbnd)
            return ;
        if(root->lbnd > val){
            if(root->lbnd == val + 1){
                root->lbnd = val;
                if(root->left){
                    TreeNode *p = root, *q = root->left;
                    //Do the merge operation
                    while(q){
                        if(q->rbnd >= root->lbnd - 1){
                            root->lbnd = q->lbnd;
                            if(p == root){
                                root->left = q->left;
                            }else{
                                p->right = q->left;
                            }
                            break;
                        }
                        q = q->right;
                        if(p == root)
                            p = p->left;
                        else
                            p = p->right;
                    }
                }
            }else{
                if(root->left)
                    solve(val, root->left);
                else{
                    TreeNode *tmp = new TreeNode(val,val);
                    root->left = tmp;
                }
            }
            return ;
        }
        if(root->rbnd < val){
            if(root->rbnd == val - 1){
                root->rbnd = val;
                if(root->right){
                    TreeNode *p = root, *q = root->right;
                    //Do the merge operation
                    while(q){
                        if(q->lbnd <= root->rbnd + 1){
                            root->rbnd = q->rbnd;
                            if(p == root){
                                root->right = q->right;
                            }else{
                                p->left = q->right;
                            }
                            return ;
                        }
                        q = q->left;
                        if(p == root)
                            p = p->right;
                        else
                            p = p->left;
                    }
                }
            }else{
                if(root->right)
                    solve(val, root->right);
                else{
                    TreeNode *tmp = new TreeNode(val,val);
                    root->right = tmp;
                }
            }
            return ;
        }
        return ;
    }

    void dfs(TreeNode *root, vector<Interval> &ans){
        if(!root)
            return ;
        Interval tmp(root->lbnd, root->rbnd);
        if(root->left)
            dfs(root->left, ans);
        ans.push_back(tmp);
        if(root->right)
            dfs(root->right, ans);
    }
    
private:
    TreeNode *root;
};
