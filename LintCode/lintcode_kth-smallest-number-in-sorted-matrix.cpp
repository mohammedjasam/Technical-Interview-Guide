/*
*
* Tag: Data Structure (Heap)
* Time: O(klgn)
* Space: O(k)
*/
class Solution {
struct Val{
    int val;
    int r, c;
    Val() {}
    Val(int v, int vr, int vc) {val=v; r=vr; c=vc;}
    bool operator < (Val a) const{
        return a.val < val;
    }
};
public:
    /**
     * @param matrix: a matrix of integers
     * @param k: an integer
     * @return: the kth smallest number in the matrix
     */
    int kthSmallest(vector<vector<int> > &matrix, int k) {
        // write your code here
        int n = matrix.size(), m = matrix[0].size(), ans;
        vector<vector<bool>> vis(n, vector<bool>(m));
        priority_queue<Val> pq;
        Val tmp(matrix[0][0], 0, 0);
//        tmp.val = matrix[0][0];
//        tmp.r = tmp.c = 0;
        vis[0][0] = 1;
        pq.push(tmp);
        while(k){
            Val u = pq.top(), v;
            int r = u.r, c = u.c;
            ans = u.val;
            pq.pop();
            if(r+1 < n && !vis[r+1][c]){
                vis[r+1][c] = 1;
                v={matrix[r+1][c],r+1,c};
                pq.push(v);
            }
            if(r+1 < n && c+1<m && !vis[r+1][c+1]){
                vis[r+1][c+1] = 1;
                v={matrix[r+1][c+1],r+1,c+1};
                pq.push(v);
            }
            if(c+1<m && !vis[r][c+1]){
                vis[r][c+1] = 1;
                v={matrix[r][c+1],r,c+1};
                pq.push(v);
            }
            k--;
        }
        
        return ans;
    }
};
