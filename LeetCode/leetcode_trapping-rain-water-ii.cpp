/*
*
* Tag: Heap
* Time: O(n^2 lgn)
* Space: O(n^2)
*/
class Solution {
struct point{
    int height, level, x, y;
    
    point(){}
    
    point (int h, int l, int v_x, int v_y){
        height = h, level = l, x = v_x, y = v_y;
    }
    
    bool operator < (const point &a)const{
        return a.level < level;
    }
};
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int sum = 0;
        if(heightMap.size() == 0 || heightMap[0].size() == 0)
            return sum;
        int n = heightMap.size(), m = heightMap[0].size(), new_level = 0, old_level = 0, v_x = 0, v_y = 0;
        priority_queue<point> pq;
        vector<vector<point>> mp(n, vector<point>(m));
        for(int i = 0; i < n; ++ i){
            for(int j = 0; j < m; ++ j){
                if(i == 0 || i == n - 1 || j == 0 || j == m - 1){
                    point pnt(heightMap[i][j], heightMap[i][j], i, j);
                    pq.push(pnt);
                    mp[i][j] = pnt;
                }else{
                    point pnt(heightMap[i][j], INT_MAX, i, j);
                    mp[i][j] = pnt;
                }
            }
        }
        
        point u, v;
        while(!pq.empty()){
            u = pq.top();
            pq.pop();
            for(int i = 0; i < 4; ++ i){
                v_x = u.x + dir[i][0], v_y = u.y + dir[i][1];
                if(v_x >= 0 && v_x < n && v_y >= 0 && v_y < m){
                    v.height = mp[v_x][v_y].height;
                    old_level = mp[v_x][v_y].level;
                    new_level = max(v.height, min(mp[v_x][v_y].level, u.level));
                    if(new_level != old_level){
                        mp[v_x][v_y].level = new_level;
                        pq.push(mp[v_x][v_y]);
                    }
                }
            }
        }
        
        for(int i = 1; i < n - 1; ++ i){
            for(int j = 1; j < m - 1; ++ j){
                sum += (mp[i][j].level - mp[i][j].height);
            }
        }
        return sum;
    }
private:
    int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
};
