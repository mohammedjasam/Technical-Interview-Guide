/*
*
* Tag: Greedy
* Time: O(nlgn)
* Space: O(1)
*/
class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        int ans = 0;
        if(points.size() == 0)
            return ans;
        sort(points.begin(), points.end(), cmp);
        pair<int,int> cur = points[0];
        ++ ans;
        for(int i = 1; i < points.size(); ++ i){
            if(cur.second >= points[i].first){
                cur.first = max(cur.first, points[i].first);
                cur.second = min(cur.second, points[i].second);
                continue;
            }
            cur = points[i];
            ++ ans;
        }
        return ans;
    }
private:
    static bool cmp(pair<int,int> &a, pair<int,int> &b){
        return a.second == b.second? a.first < b.first:a.second < b.second;
    }
};
