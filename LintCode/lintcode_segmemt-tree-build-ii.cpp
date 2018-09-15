/*
*
* Tag: Data Structure
* Time: O(n)
* Space: O(1)
*/
/**
 * Definition of SegmentTreeNode:
 * class SegmentTreeNode {
 * public:
 *     int start, end, max;
 *     SegmentTreeNode *left, *right;
 *     SegmentTreeNode(int start, int end, int max) {
 *         this->start = start;
 *         this->end = end;
 *         this->max = max;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     *@param A: a list of integer
     *@return: The root of Segment Tree
     */
    SegmentTreeNode * build(vector<int>& A) {
        // write your code here
        SegmentTreeNode *root = NULL;
        if(!A.size())
            return root;
        int n = A.size();
        root = dfs(0, n - 1, A);
        return root;
    }
private:    
    SegmentTreeNode * dfs(int start, int ends, vector<int>& A){
        SegmentTreeNode *root = new SegmentTreeNode(start, ends, 0);
        if(start >= ends){
            root->max = A[start];
            return root;
        }
        int mid = (start + ends)>>1;
        root->left = dfs(start, mid, A);
        root->right = dfs(mid + 1, ends, A);
        root->max = max(root->left->max, root->right->max);
        return root;
    }
};
