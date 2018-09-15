/*
*
* Tag: Brute Force
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        for(int i = 0; i < ops.size(); ++ i){
            m = min(m, ops[i][0]);
            n = min(n, ops[i][1]);
        }
        return m*n;
    }
};
