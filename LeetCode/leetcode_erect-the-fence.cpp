/*
*
* Tag: Geometry
* Time: O(nlgn)
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
    vector<Point> outerTrees(vector<Point>& points) {
        if(points.size() < 3)
            return points;
        int n = points.size(), top = 1;
        vector<Point> ans(2*n + 10);
        sort(points.begin(), points.end(), cmp);
        ans[0] = points[0], ans[1] = points[1];
        for(int i = 2; i < n; ++ i){
            while(top > 0 && cross(ans[top], points[i], ans[top - 1]) < 0)
                -- top;
            ans[++ top] = points[i];
        }
        for(int i = n - 2, tmp = top; i >= 0; -- i){
            while(top > tmp && cross(ans[top], points[i], ans[top - 1] ) < 0)
                -- top;
            ans[++ top] = points[i];
        }
        
        ans.resize(top);
        sort(ans.begin(), ans.end(), cmp);
        ans.erase(unique(ans.begin(), ans.end(), equ), ans.end());
        return ans;
    }
private:
    int cross(Point &p0, Point &p1, Point &p2) {
        return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
    }

    static bool equ(Point &p1, Point &p2) { return p1.x == p2.x && p1.y == p2.y; }
    
    static bool cmp(Point &p1, Point &p2){
        return p1.y < p2.y || (p1.x < p2.x && p1.y == p2.y);
	}
    
};
