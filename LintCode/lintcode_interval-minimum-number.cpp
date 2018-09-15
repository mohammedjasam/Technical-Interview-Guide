/*
*
* Tag: Data Structure (Segment Tree)
* Time: O(nlgn)
* Space: O(nlgn)
*/
/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 
 
class SegmentTreeNode {
  public:
    int start, end, minval;
    SegmentTreeNode *left, *right;
    SegmentTreeNode(int start, int end) {
         this->start = start, this->end = end;
         this->left = this->right = NULL;
         this->minval = 0;
   }
};
*/

class Solution {
class SegmentTreeNode {
   public:
      int start, end, minval;
      SegmentTreeNode *left, *right;
      SegmentTreeNode(int start, int end) {
          this->start = start;
          this->end = end;
          this->minval = 0;
          this->left = this->right = NULL;
      }
};

public:
    /**
     *@param A, queries: Given an integer array and an query list
     *@return: The result list
     */
    vector<int> intervalMinNumber(vector<int> &A, vector<Interval> &queries) {
        // write your code here
        vector<int> ans;
        if(A.size() == 0 || queries.size() == 0)
            return ans;
        int n = A.size();
        SegmentTreeNode *root = build(0, n - 1, A);
        ans.resize(queries.size());
        for(int i = 0; i < queries.size(); ++ i){
            ans[i] = query(root, queries[i].start, queries[i].end);
        }
        return ans;
    }
    
    SegmentTreeNode * build(int start, int end, vector<int> &A) {
        // write your code here
        if(start > end)
            return NULL;
        SegmentTreeNode *node = new SegmentTreeNode(start, end);
        if(start == end){
            node->minval = A[start];
            return node;
        }
        int mid = (start + end)>>1;
        node->left = build(start, mid, A);
        node->right = build(mid + 1, end, A);
        node->minval = min(node->left->minval, node->right->minval);
        return node;
    }
    
    int query(SegmentTreeNode *root, int start, int end) {
        // write your code here
        if(root->left == root->right)
            return root->minval;
        if(root->start == start && root->end == end)
            return root->minval;
        int mid = (root->start + root->end)/2;
        if(end <= mid)
            return query(root->left, start, end);
        else if(start > mid)
            return query(root->right, start, end);
        else{
            return min(query(root->left, start, mid), query(root->right, mid+1, end));
        }
    }
};
