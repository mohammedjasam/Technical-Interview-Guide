/*
*
* Tag: DFS
* Time
* Space
*/
class Solution {
public:
    /**
     * @param digits A digital string
     * @return all posible letter combinations
     */
    vector<string> letterCombinations(string& digits) {
        // Write your code here
        vector<string> ans;
        if(digits.size() == 0){
            return ans;
        }
        int dep = digits.size();
        string tmp(dep, '0');
        dfs(0, dep, tmp, ans, digits);
        return ans;
    }
    
    void dfs(int cur, int dep, string &tmp, vector<string> &ans, string& digits){
        if(cur >= dep){
            ans.push_back(tmp);
            return ;
        }
        for(int i = 0; i < dic[digits[cur] - '0'].size(); ++ i){
            tmp[cur] = dic[digits[cur] - '0'][i];
            dfs(cur + 1, dep, tmp, ans, digits);
        }
    }
private:
string dic[10] = {{""},{""},{"abc"},{"def"},{"ghi"},{"jkl"},{"mno"},{"pqrs"},{"tuv"},{"wxyz"}};
};
