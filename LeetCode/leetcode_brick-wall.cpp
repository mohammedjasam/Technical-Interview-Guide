/*
*
* Tag: Hash
* Time: O(nm)
* Space: O(nm)
*/
class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int ans = 0;
        if(wall.size() < 1)
            return ans;
        
        unordered_map<int,int> dict;
        unordered_map<int,int>::iterator it;
        
        int n = wall.size();
        
        for(int i = 0; i < n; ++ i){
            int sum = 0;
            for(int j = 0; j < wall[i].size(); ++ j){
                sum += wall[i][j];
                if(j != wall[i].size() - 1){
                    ++ dict[sum];
                }
            }
        }
        if(dict.size() == 0)
            return n;
        ans = INT_MAX;
        for(it = dict.begin(); it != dict.end(); ++ it){
            ans = min(ans, n - it->second);
        }
        return ans;
    }
};
