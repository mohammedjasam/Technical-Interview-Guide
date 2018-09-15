/*
*
* Tag: Math
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    int minDistance(int height, int width, vector<int>& tree, vector<int>& squirrel, vector<vector<int>>& nuts) {
        int sum = 0, ans = INT_MAX, nutsum = 0, squirrelsum = 0;
        int n = nuts.size();
        for(int i = 0; i < n; ++ i){
            nutsum = 0;
            for(int j = 0; j < tree.size(); ++ j){
                nutsum += abs(nuts[i][j] - tree[j]);
            }
            sum += 2*nutsum;
        }
        for(int i = 0; i < n; ++ i){
            squirrelsum = nutsum = 0;
            for(int j = 0; j < squirrel.size(); ++ j){
                squirrelsum += abs(nuts[i][j] - squirrel[j]);
                nutsum += abs(nuts[i][j] - tree[j]);
            }
            ans = min(ans, sum - nutsum + squirrelsum);
        }
        return ans;
    }
};
