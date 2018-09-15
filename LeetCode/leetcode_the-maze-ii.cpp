/*
*
* Tag: BFS
* Time: O(n^2)
* Space: O(n^2)
*/
class Solution {
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole) {
        int n = maze.size(), m = maze[0].size();
        vector<vector<int>> dist(n, vector<int>(m, -1));
        queue<pair<int,int>> q;
        pair<int,int> cur;
        int x, y, step;
        q.push({ball[0], ball[1]});
        dist[ball[0]][ball[1]] = 0;
        
        while(!q.empty()){
            cur = q.front();
            q.pop();
            for(int i = 0; i < 4; ++ i){
                x = cur.first, y = cur.second;
                step = 0;
                while(x + dir[i][0] >= 0 && x + dir[i][0] < n && y + dir[i][1] >= 0 && y + dir[i][1] < m 
                    && maze[x + dir[i][0]][y + dir[i][1]] == 0){
                        ++ step;
                        x += dir[i][0];
                        y += dir[i][1];
                }
                if(dist[x][y] == -1 || dist[x][y] > dist[cur.first][cur.second] + step){
                    dist[x][y] = dist[cur.first][cur.second] + step;
                    q.push({x, y});
                }
            }
        }
        
        return dist[hole[0]][hole[1]];
    }
private:
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
};
