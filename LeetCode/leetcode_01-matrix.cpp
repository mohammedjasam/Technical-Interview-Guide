/*
*
* Tag: BFS
* Time: O(nm)
* Space: O(nm)
*/
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        if(matrix.size() == 0)
            return matrix;
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> ans(n, vector<int>(m, n*m));
        queue<pair<int,int>> q;
        pair<int,int> cur, nxt;
        for(int i = 0; i < n; ++ i){
            for(int j = 0; j < m; ++ j){
                if(matrix[i][j] == 0){
                    ans[i][j] = 0;
                    q.push(make_pair(i,j));
                }
            }
        }
        while(!q.empty()){
            cur = q.front();
            q.pop();
            for(int i = 0; i < 4; ++ i){
                nxt.first = cur.first + dir[i][0], nxt.second = cur.second + dir[i][1];
                if((nxt.first >= 0 && nxt.first < n && nxt.second >= 0 && nxt.second < m) && 
                    ans[nxt.first][nxt.second] > ans[cur.first][cur.second] + 1){
                        ans[nxt.first][nxt.second] = ans[cur.first][cur.second] + 1;
                        q.push(make_pair(nxt.first, nxt.second));
                    }
            }
        }
        return ans;
    }

private:
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
};
