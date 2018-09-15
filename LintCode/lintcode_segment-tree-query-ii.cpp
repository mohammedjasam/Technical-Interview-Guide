/*
*
* Tag: Data Structure (Segment Tree)
* Time: O(nlgn)
* Space: O(nlgn)
*/
/**
 * Definition of SegmentTreeNode:
 * class SegmentTreeNode {
 * public:
 *     int start, end, count;
 *     SegmentTreeNode *left, *right;
 *     SegmentTreeNode(int start, int end, int count) {
 *         this->start = start;
 *         this->end = end;
 *         this->count = count;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     *@param root, start, end: The root of segment tree and 
     *                         an segment / interval
     *@return: The count number in the interval [start, end] 
     */
    int query(SegmentTreeNode *root, int start, int end) {
        // write your code here
        int ans = 0;
        if(!root)
            return ans;
        if(start < root->start)
            start = root->start;
        if(end > root->end)
            end = root->end;
        if(root->start == start && root->end == end){
            ans = root->count;
            return ans;
        }
        int mid = (root->start + root->end)/2;
        if(end <= mid)
            ans = query(root->left, start, end);
        else if(start > mid)
            ans = query(root->right, start, end);
        else{
            ans = query(root->left, start, mid) + query(root->right, mid + 1, end);
        }
        return ans;
    }
};
