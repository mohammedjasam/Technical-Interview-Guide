/*
*
* Tag:
* Time:
* Space:
*/
class Solution {
private:
    const int FLOW_TO_PAC = 1;
    const int FLOW_TO_ATL = 2;
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &matrix) {
        vector<vector<int>> ans;
        if(matrix.size() == 0)
            return ans;
        
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> visit(n, vector<int>(m, 0));
        init(visit, n, m);
        
        markAllPointsCanFlowToPacOrAtl(matrix, visit, n, m);
        
        savedPointsCanFlowToPacAndAtl(visit, ans, n, m);
        
        return ans;
    }
    
private:
    void init(vector<vector<int>> &visit, int n, int m){
        for(int i = 0; i < n; ++ i) {
            visit[i][0] |= FLOW_TO_PAC;
            visit[i][m - 1] |= FLOW_TO_ATL;
        }
        
        for(int i = 0; i < m; ++ i) {
            visit[0][i] |= FLOW_TO_PAC;
            visit[n - 1][i] |= FLOW_TO_ATL;
        }
    }
    
    void markAllPointsCanFlowToPacOrAtl(vector<vector<int>> &matrix, vector<vector<int>> &visit, int n, int m){
        for(int i = 0; i < n; ++ i){
            dfsInAllDirs(i, 0, FLOW_TO_PAC, matrix, visit, n, m);
            
            dfsInAllDirs(i, m - 1, FLOW_TO_ATL, matrix, visit, n, m);
        }
        
        for(int i = 0; i < m; ++ i){
            dfsInAllDirs(0, i, FLOW_TO_PAC, matrix, visit, n, m);
            
            dfsInAllDirs(n - 1, i, FLOW_TO_ATL, matrix, visit, n, m);
        }
    }
    
    void dfsInAllDirs(int curX, int curY, int status, vector<vector<int>> &matrix, vector<vector<int>> &visit, int n, int m){
        int curHeight = matrix[curX][curY];
        for(int j = 0; j < 4; ++ j){
            pair<int,int> startPoint = make_pair(curX + dir[j][0], curY + dir[j][1]);
            if(!isInGrid(startPoint, n, m))
                continue;
            
            int nextHeight = matrix[startPoint.first][startPoint.second];
            if(curHeight <= nextHeight)
                dfs(startPoint, matrix, n, m, visit, status);
        }
    }
    
    void dfs(pair<int,int> point, vector<vector<int>> &matrix, int n, int m, vector<vector<int>> &visit, int status) {
        if((visit[point.first][point.second]&status) != 0)
            return ;
        
        visit[point.first][point.second] |= status;
        
        dfsInAllDirs(point.first, point.second, status, matrix, visit, n, m);
    }
    
    bool isInGrid(pair<int,int> point, int n, int m){
        return point.first >= 0 && point.first < n && point.second >= 0 && point.second < m;
    }
    
    void savedPointsCanFlowToPacAndAtl(vector<vector<int>> &visit, vector<vector<int>> &ans, int n, int m){
        for(int i = 0; i < n; ++ i){
            for(int j = 0; j < m; ++ j){
                if( canFlowToPac(visit, i, j) && canFlowToAtl(visit, i, j) ){
                    vector<int> ansPoint = {i, j};
                    ans.push_back(ansPoint);
                }
            }
        }
    }
    
    bool canFlowToPac(vector<vector<int>> &visit, int x, int y){
        return (visit[x][y] & FLOW_TO_PAC);
    }
    
    bool canFlowToAtl(vector<vector<int>> &visit, int x, int y){
        return (visit[x][y] & FLOW_TO_ATL);
    }
    
private:
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
};
