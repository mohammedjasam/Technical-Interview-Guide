/*
*
* Tag: BFS
* Time: O(n^2)
* Space: O(n^2)
*/
class Solution {
public:
    /**
     * @param rooms: m x n 2D grid
     * @return: nothing
     */
    void wallsAndGates(vector<vector<int>> &rooms) {
        if( rooms.size() == 0 ) {
            return ;
        }
        
        vector<pair<int,int>> gates = findGatesOf(rooms);
        
        for(pair<int,int> gate: gates){
            bfs(gate, rooms);
        }
        
        return ;
    }
private:
    vector<pair<int,int>> findGatesOf(vector<vector<int>> &rooms) {
        vector<pair<int,int>> gates;
        
        for(int row = 0; row < rooms.size(); ++ row) {
            for(int col = 0; col < rooms[row].size(); ++ col) {
                if(rooms[row][col] == 0){
                    gates.push_back(make_pair(row, col));
                }
            }
        }
        
        return gates;
    }
    
    void bfs(pair<int,int> gate, vector<vector<int>> &rooms){
        queue<pair<int,int>> q;
        q.push(gate);
        
        int numOfRows = rooms.size(), numOfCols = rooms[0].size();
        
        while(!q.empty()) {
            pair<int,int> curPoint = q.front();
            q.pop();
            
            for(int i = 0; i < 4; ++ i){
                pair<int,int> nextPoint = make_pair(curPoint.first + dir[i][0], curPoint.second + dir[i][1]);
                
                if(isOutOfRoom(nextPoint, numOfRows, numOfCols)){
                    continue;
                }
                
                int dist = rooms[curPoint.first][curPoint.second] + 1;
                if(dist < rooms[nextPoint.first][nextPoint.second]) {
                    rooms[nextPoint.first][nextPoint.second] = dist;
                    q.push(nextPoint);
                }
            }
        }
    }
    
    bool isOutOfRoom(pair<int,int> gate, int numOfRows, int numOfCols){
        return gate.first < 0 || gate.first >= numOfRows || gate.second < 0 || gate.second >= numOfCols;
    }
    
private:
    int dir[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
};
