/*
*
* Tag: Math && Sort
* Time: O(nm)
* Space: O(n + m)
*/
class Solution {
public:
    /**
     * @param grid: a 2D grid
     * @return: the minimize travel distance
     */
    int minTotalDistance(vector<vector<int>> &grid) {
        if(grid.size() == 0)
            return 0;
        
        vector<int> xPoints, yPoints;
        updateXYPoints(xPoints, yPoints, grid);
        
        sort(xPoints.begin(), xPoints.end());
        sort(yPoints.begin(), yPoints.end());
        
        int minDistInX = calculateDist(xPoints);
        int minDistInY = calculateDist(yPoints);
        
        return minDistInX + minDistInY;
    }

private:
    void updateXYPoints(vector<int> &xPoints, vector<int> &yPoints, vector<vector<int>> &grid) {
        int n = grid.size(), m = grid[0].size();
        for(int i = 0; i < n; ++ i){
            for(int j = 0; j < m; ++ j){
                if(grid[i][j] == 1) {
                    xPoints.push_back(i);
                    yPoints.push_back(j);
                }
            }
        }
    }

    int calculateDist(vector<int> &points){
        int n = points.size();
        if(n%2 == 1)
            return calculateDistAmongPoints(points[n/2], points);
        else
            return min(calculateDistAmongPoints(points[n/2 - 1], points), calculateDistAmongPoints(points[n/2 - 1], points));
    }
    
    int calculateDistAmongPoints(int point, vector<int> &points){
        int res = 0;
        
        for(int i = 0; i < points.size(); ++ i)
            res += abs(points[i] - point);
        
        return res;
    }
};
