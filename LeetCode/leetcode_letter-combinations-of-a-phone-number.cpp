/*
*
* Tag: DFS
* Time: O(3^n)
* Space: O(n)
*/
class Solution {
private:
    string dic[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.size() == 0)
            return ans;
        
        int dep = digits.size();
        string tmp(dep, 0);
        dfs(tmp, 0, dep, ans, digits);
        return ans;
    }

private:
    void dfs(string &tmp, int curdep, int dep, vector<string> &ans, string digits){
        if(curdep >= dep){
            ans.push_back(tmp);
            return ;
        }
        for(int i = 0; i < dic[digits[curdep] - '0'].size(); ++ i){
            tmp[curdep] = dic[digits[curdep] - '0'][i];
            dfs(tmp, curdep + 1, dep, ans, digits);
        }
    }
};
