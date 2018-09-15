/*
*
* Tag: Implementation
* Time: O(n*m)
* Space: O(1)
*/
class Solution {
private:
    int dir[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}, {0, -1}};
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        int r = M.size(), c = M[0].size();
        vector<vector<int>> ans(r, vector<int>(c, 0));
        
        for(int i = 0; i < r; ++ i){
            for(int j = 0; j < c; ++ j){
                ans[i][j] = getAverageGrayScale(i, j, M);
            }
        }
        
        return ans;
    }
    
private:
    int getAverageGrayScale(int x, int y, vector<vector<int>>& M){
        int sum = M[x][y], cnt = 1;
        int r = M.size(), c = M[0].size();
        for(int i = 0; i < 8; ++ i){
            int nextX = x + dir[i][0], nextY = y + dir[i][1];
            if(nextX >= 0 && nextX < r && nextY >= 0 && nextY < c) {
                ++ cnt;
                sum += M[nextX][nextY];
            }
        }
        
        return sum/cnt;
    }
};
