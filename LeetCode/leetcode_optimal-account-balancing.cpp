/*
*
* Tag: DFS
* Time: O(n^2)
* Space: O(n)
*/
class Solution {
public:
    int minTransfers(vector<vector<int>>& transactions) {
        unordered_map<int,long long> account;
        for(int i = 0; i < transactions.size(); ++ i){
            account[transactions[i][0]] -= (long long)transactions[i][2];
            account[transactions[i][1]] += (long long)transactions[i][2];
        }
        vector<int> vec;
        for(unordered_map<int,long long>::iterator it = account.begin(); it != account.end(); ++ it){
            if(it->second != 0)
                vec.push_back(it->second);
        }
        return dfs(vec, 0, vec.size(), 0);
    }
    
private:
    int dfs(vector<int> &vec, int start, int n, int cnt){
        int ans = INT_MAX;
        while(start < n && vec[start] == 0) ++ start;
        for(int i = start + 1; i < n; ++ i){
            if((vec[i] < 0 && vec[start] > 0) || (vec[i] > 0 && vec[start] < 0)){
                vec[i] += vec[start];
                ans = min(ans, dfs(vec, start + 1, n, cnt + 1));
                vec[i] -= vec[start];
            }
        }
        return ans == INT_MAX?cnt:ans;
    }
};
