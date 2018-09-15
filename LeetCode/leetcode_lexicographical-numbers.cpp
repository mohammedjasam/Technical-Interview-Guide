/*
*
* Tag: DFS
* Time: O(n)
* Space: O(lgn)
*/
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans(n);
        if(!n)
            return ans;
        int cnt = 0;
        dfs(0, n, 0, cnt, ans);
        return ans;
    }
private:
    void dfs(int dep, int &n, int cur, int &cnt, vector<int> &ans){
        cur *= 10;
        for(int i = 0; i <= 9; ++ i){
            int nxt = cur + i;
            if(!nxt)
                continue;
            if(nxt > n)
                break;
            ans[cnt ++] = nxt;
            dfs(dep + 1, n, nxt, cnt, ans);
        }
    }
};
