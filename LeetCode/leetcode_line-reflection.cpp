/*
*
* Tag: Hash
* Time: O(n)
* Space: O(n)
*/
class Solution {
public:
    bool isReflected(vector<pair<int, int>>& points) {
        if((int)points.size() <= 1)
            return true;
        int y = 0, minx = INT_MAX, maxx = INT_MIN;
        for(int i = 0; i < points.size(); ++ i){
            minx = min(minx, points[i].first);
            maxx = max(maxx, points[i].first);
            xy_axis.insert(points[i]);
        }
        y = maxx + minx;
        set<pair<int, int>>::iterator it = xy_axis.begin();
        for(; it != xy_axis.end(); ++ it){
            pair<int,int> tmp = *it;
            if(xy_axis.find({y - tmp.first, tmp.second}) == xy_axis.end())
                return false;
        }
        return true;
    }
private:
   set<pair<int, int>> xy_axis;  
};

class Solution {
public:
    bool isReflected(vector<pair<int, int>>& points) {
        if((int)points.size() <= 1)
            return true;
        int y = 0, minx = INT_MAX, maxx = INT_MIN;
        for(int i = 0; i < points.size(); ++ i){
            minx = min(minx, points[i].first);
            maxx = max(maxx, points[i].first);
            xy_axis[points[i].second].insert(points[i].first);
        }
        y = maxx + minx;
        for(int i = 0; i < points.size(); ++ i){
            if(xy_axis[points[i].second].find(y - points[i].first) == xy_axis[points[i].first].end())
                return false;
        }
        return true;
    }
private:
   unordered_map<int, unordered_set<int>> xy_axis;  
};
