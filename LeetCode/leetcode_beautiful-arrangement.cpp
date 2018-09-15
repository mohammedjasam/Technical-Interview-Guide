/*
*
* Tag: DFS
* Time: O(5^n)
* Space: O(n)
*/
class Solution {
private:
    vector<vector<int>> tbl = {
        {},
        {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15},
        {1,2,4,6,8,10,12,14},
        {1,3,6,9,12,15},
        {1,2,4,8,12},
        {1,5,10,15},
        {1,2,3,6,12},
        {1,7,14},
        {1,2,4,8},
        {1,3,9},
        {1,2,5,10},
        {1,11},
        {1,2,3,4,6,12},
        {1,13},
        {1,2,7,14},
        {1,3,5,15}
    };
    
 private:   
    void dfs(int dep, int &ans, int state, int N){
        if(dep > N){
            ++ ans;
            return ;
        }
        int mask = 1;
        for(int i = 0; i < tbl[dep].size() && tbl[dep][i] <= N; ++ i){
            mask = (1<<tbl[dep][i]);
            if( (mask&state) == 0 ){
                if( tbl[dep][i]%dep == 0 || dep%tbl[dep][i] == 0 ){
                    dfs(dep + 1, ans, (state | (1<<tbl[dep][i])), N);
                }
            }
        }
    }
    
public:
    int countArrangement(int N) {
        int state = 0, ans = 0;
        dfs(1, ans, state, N);
        return ans;
    }
};
