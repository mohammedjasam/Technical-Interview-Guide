/*
*
* Tag: Computation Geometry
* Time: O(n^2)
* Space: O(n)
*/
/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    /**
     * @param points an array of point
     * @return an integer
     */
    int maxPoints(vector<Point>& points) {
        // Write your code here
        int ans = 0;
        if(!points.size())
            return ans;
        int n = points.size();
        for(int i = 0; i < n; ++ i){
            Point p1 = points[i];
            unordered_map<double,int> pcnt;
            pcnt[INT_MIN] = 0;
            
            int dup = 1;
            for(int j = 0; j < n; ++ j){
                if(i == j)
                    continue;
                Point p2 = points[j];
                if(p1.x == p2.x && p1.y == p2.y)
                    ++ dup;
                else{
                    double k = p1.x==p2.x?INT_MAX:((p2.y - p1.y)*1.0)/((p2.x - p1.x)*1.0);
                    ++ pcnt[k];
                }
            }
            
            unordered_map<double,int>::iterator it;
            for(it = pcnt.begin(); it != pcnt.end(); ++ it)
                ans = max(ans, it->second + dup);
        }
        
        return ans;
    }
};
