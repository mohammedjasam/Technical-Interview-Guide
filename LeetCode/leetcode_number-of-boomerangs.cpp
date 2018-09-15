/*
*
* Tag: Hash
* Time: O(n)
* Space: O(n)
*/
class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int ans = 0;
        if(points.size() == 0)
            return ans;
        unordered_map<int,int> dict;
        unordered_map<int,int>::iterator it;
        int dist = 0;
        for(int i = 0; i < points.size(); ++ i){
            dict.clear();
            for(int j = 0; j < points.size(); ++ j){
                if(i == j)
                    continue;
                dist = calDist(points[i], points[j]);
                ++ dict[dist];
            }
            for(it = dict.begin(); it != dict.end(); ++ it){
                ans += getPairCnt(it->second);
            }
        }
        return ans;
    }
private:
    int calDist(pair<int,int> a, pair<int,int> b){
        return (a.first - b.first)*(a.first - b.first) + (a.second - b.second)*(a.second - b.second);
    }
    
    int getPairCnt(int n){
        return n < 2? 0 : n*(n - 1);
    }
};
