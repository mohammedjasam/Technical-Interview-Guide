/*
*
* Tag: Binary Search + BFS
* Time: O((n^2)lgn)
* Space: O(n^2)
*/
class Solution {
private:
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
public:
    int swimInWater(vector<vector<int>>& grid) {
        int ans = 0;
        if(grid.size() == 0 ) {
            return ans;
        }
        
        int n = grid.size();
        int l = 1, r = n*n - 1;
        while(l <= r){
            int mid = (l + r)>>1;
            if(canReachToDestination(grid, mid)){
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        
        return ans;
    }
    
private:
    bool canReachToDestination(vector<vector<int>>& grid, int time){
        if(time < grid[0][0]){
            return false;
        }
        
        int n = grid.size();
        vector<vector<bool>> visitedGrid(n, vector<bool>(n, false));
        queue<pair<int,int>> q;
        q.push(make_pair(0, 0));
        visitedGrid[0][0] = 1;
        
        while(!q.empty()){
            pair<int,int> curPos = q.front();
            q.pop();
            
            for(int i = 0; i < 4; ++ i){
                pair<int,int> nxtPos = make_pair(curPos.first + dir[i][0], curPos.second + dir[i][1]);
                if(nxtPos.first >= 0 && nxtPos.first < n && nxtPos.second >= 0 && nxtPos.second < n && grid[nxtPos.first][nxtPos.second] <= time && !visitedGrid[nxtPos.first][nxtPos.second]){
                    q.push(make_pair(nxtPos.first, nxtPos.second));
                    visitedGrid[nxtPos.first][nxtPos.second] = 1;
                }
            }
        }
        
        return visitedGrid[n - 1][n - 1];
    }
};
