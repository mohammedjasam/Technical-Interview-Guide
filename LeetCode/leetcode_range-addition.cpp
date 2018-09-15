/*
*
* Tag: DP (Trick)
* Time: O(k+n)
* Space: O(1)
*/
class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> ans(length, 0), tmp(length + 1, 0);
        if(!length || !updates.size())
            return ans;
        int sta = length, ends = 0;
        for(int i = 0; i < updates.size(); ++ i){
            sta = min(sta, updates[i][0]);
            ends = max(ends, updates[i][1]);
            tmp[updates[i][0]] += updates[i][2];
            tmp[updates[i][1] + 1] -= updates[i][2];
        }
        ans[sta] = tmp[sta];
        for(int i = sta + 1; i <= ends; ++ i){
            ans[i] = tmp[i] + ans[i - 1];
        }
        return ans;
    }
};
