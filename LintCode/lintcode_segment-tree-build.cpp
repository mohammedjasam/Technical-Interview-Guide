/*
*
* Tag: Data Structure (Segment Tree)
* Time: O(nlgn)
* Space: O(n)
*/
/**
 * Definition of SegmentTreeNode:
 * class SegmentTreeNode {
 * public:
 *     int start, end;
 *     SegmentTreeNode *left, *right;
 *     SegmentTreeNode(int start, int end) {
 *         this->start = start, this->end = end;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     *@param start, end: Denote an segment / interval
     *@return: The root of Segment Tree
     */
    SegmentTreeNode * build(int start, int end) {
        // write your code here
        if(start > end)
            return NULL;
        SegmentTreeNode *node = new SegmentTreeNode(start, end);
        if(start == end)
            return node;
        int mid = (start + end)>>1;
        node->left = build(start, mid);
        node->right = build(mid + 1, end);
        return node;
    }
};
