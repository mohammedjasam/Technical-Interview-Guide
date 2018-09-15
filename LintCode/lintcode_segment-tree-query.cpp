/*
*
* Tag: Data Structure (Segment Tree)
* Time: O(lgn)
* Space: O(lgn)
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
     *@param root, start, end: The root of segment tree and 
     *                         an segment / interval
     *@return: The maximum number in the interval [start, end]
     */
    int query(SegmentTreeNode *root, int start, int end) {
        // write your code here
        if(root->left == root->right)
            return root->max;
        if(root->start == start && root->end == end)
            return root->max;
        int mid = (root->start + root->end)/2;
        if(end <= mid)
            return query(root->left, start, end);
        else if(start > mid)
            return query(root->right, start, end);
        else{
            return max(query(root->left, start, mid), query(root->right, mid+1, end));
        }
    }
};
