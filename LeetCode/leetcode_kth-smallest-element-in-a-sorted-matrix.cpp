/*
*
* Tag: Data Structure (Heap)
* Time: O(nlgn) where n is the number of cells in the matrix.
* Space: O(n)
*/
class Solution {
private:
    struct node {
        int r, c, val;
        bool operator < (const node &a)const{
            return a.val < val;
        }
    };
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<node> pq;
        vector<vector<bool>> vis(matrix.size(), vector<bool>(matrix[0].size(), false));
        int ans = 0;
        node cur, nxt;
        cur.r = cur.c = 0, cur.val = matrix[0][0];
        pq.push(cur);
        
        vis[0][0] = true;
        while(k > 0){
            cur = pq.top();
            pq.pop();
            ans = cur.val;
            -- k;
            
            int r = cur.r, c = cur.c;
            if(r + 1 < matrix.size() && !vis[r + 1][c]){
                nxt.r = r + 1, nxt.c = c, nxt.val = matrix[r + 1][c];
                vis[nxt.r][nxt.c] = true;
                pq.push(nxt);
            }
            if(c + 1 < matrix[0].size()  && !vis[r][c + 1]){
                nxt.r = r, nxt.c = c + 1, nxt.val = matrix[r][c + 1];
                vis[nxt.r][nxt.c] = true;
                pq.push(nxt);
            }
        }
        
        return ans;
    }
};
