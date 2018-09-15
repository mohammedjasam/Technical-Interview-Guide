/*
*
* Tag: DFS
* Time: O(2^n)
* Space: O(n)
*/
class Solution {
public:
    /**
     * @param n n pairs
     * @return All combinations of well-formed parentheses
     */
    vector<string> generateParenthesis(int n) {
        // Write your code here
        vector<string> ans;
        if(!n)
            return ans;
        string str(2*n, ' ');
        dfs(0, 0, 0, str, n, ans);
        return ans;
    }
private:
    void dfs(int dep, int lcnt, int rcnt, string str, int n, vector<string> &ans){
        if(dep >= 2*n){
            ans.push_back(str);
            return ;
        }
        if(lcnt < n){
            str[dep] = '(';
            dfs(dep + 1, lcnt + 1, rcnt, str, n, ans);
        }
        if(lcnt && lcnt > rcnt && rcnt < n){
            str[dep] = ')';
            dfs(dep + 1, lcnt, rcnt + 1, str, n, ans);
        }
    }
};
