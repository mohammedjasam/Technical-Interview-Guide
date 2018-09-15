/*
*
* Tag: BFS
* Time: O(n^2)
* Space: O(n^2)
*/
class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole) {
        queue<pair<int,int>> q;
        pair<int,int> cur, tmpcur, pre;
        int step = 0;
        vector<vector<bool>> vis(maze.size(), vector<bool>(maze[0].size(), false));
        
        vis[ball[0]][ball[1]] = true;
        q.push(make_pair(ball[0],ball[1]));
        while(!q.empty()){
            cur = q.front();
            q.pop();
            for(int i = 0; i < 4; ++ i){
                step = 0;
                tmpcur = pre = cur;
                while(checkLocation(tmpcur, cur, maze, vis, hole)){
                    pre = tmpcur;
                    tmpcur = make_pair(pre.first + dir[i][0], pre.second + dir[i][1]);
                    ++ step;
                }
                if(pre.first == hole[0] && pre.second == hole[1]){
                    return true;
                }else if(maze[pre.first][pre.second] == 0 && !vis[pre.first][pre.second] && step > 1){
                    tmpcur = pre;
                    vis[pre.first][pre.second] = 1;
                    q.push(tmpcur);
                }
            }
        }
        return false;
    }
private:
    bool checkLocation(pair<int,int>& cur, pair<int,int>& start, vector<vector<int>>& maze, vector<vector<bool>>&  vis, vector<int>& hole){
        if((cur.first < 0 || cur.first >= maze.size() || cur.second < 0 || cur.second >= maze[0].size()) 
         || maze[cur.first][cur.second] == 1 || (!vis[cur.first][cur.second] && cur.first != start.first && cur.second != start.second))
            return false;
        return true;
    }
    
private:
    int dir[4][2] = {{1,0},{0,-1},{0,1},{-1,0}};
};
