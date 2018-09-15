/*
*
* Tag: DFS
* Time: O(2^n)
* Space: O(n)
*/

class Solution {
public:
    vector<string> generateAbbreviations(string &word) {
        vector<string> ans;
        if(!word.size()){
            ans.push_back("");
            return ans;
        }
        
        int n = word.size();
        string res = "";
        res = "1";
        dfs(1, 1, res, n, word, ans);
        
        res = "";
        res += word[0];
        dfs(1, 0, res, n, word, ans);
        
        return ans;
    }
    
private:
    void dfs(int sta, int cnt, string res, int n, string &word, vector<string> &ans){
        if(sta == n){
            ans.push_back(res);
            return ;
        }
        
        int m = res.size();
        string tmp_res = res;
        while(tmp_res[m - 1] >= '0' && tmp_res[m - 1] <= '9' && m){
            tmp_res.pop_back();
            m --;
        }
        tmp_res += to_string(cnt + 1);
        dfs(sta + 1, cnt + 1,  tmp_res, n, word, ans);
        
        tmp_res = res;
        tmp_res += word[sta];
        dfs(sta + 1, 0,  tmp_res, n, word, ans);
    }
};
