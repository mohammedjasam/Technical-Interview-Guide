/*
*
* Tag: Math
* Time: O(n^3)
* Space: O(1)
*/
class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double ans = 0;
        if(points.size() < 3){
            return ans;
        }
        
        for(int i = 0; i < points.size(); ++ i){
            for(int j = i + 1; j < points.size(); ++ j){
                for(int k = j + 1; k < points.size(); ++ k){
                    double area = calculateAreaOf(points[i], points[j], points[k]);
                    ans = max(ans, area);
                }
            }
        }
        
        return ans;
    }
private:
    double calculateAreaOf(vector<int> &point1, vector<int> &point2, vector<int> &point3){
        return abs(point1[0]*(point2[1] - point3[1]) + point2[0]*(point3[1] - point1[1]) + point3[0]*(point1[1] - point2[1]) )/2.0;
    }
};
