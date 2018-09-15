/*
* Algorithm: DFS + Hash
* Time complexity: O(3^len(digits))
* Memory complexity: O(3^len(digits))
*/
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<string> ans;
        string dic[] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        if(digits.size() == 0) {
            ans.push_back("");
            return ans;
        }
        int depth = digits.size();
        for(int i = 0; i < dic[digits[0] - '0'].size(); i ++){
            string tmp = "";
            tmp = dic[digits[0] - '0'][i];
            dfs(tmp,1,depth,ans,dic,digits);
        }
        return ans;
    }
    
    void dfs(string tmp, int curdep, int depth, vector<string> &ans,string dic[],string digits){
        if(curdep >= depth){
            ans.push_back(tmp);
            return ;
        }
        for(int i = 0; i < dic[digits[curdep] - '0'].size(); i ++){
            string tmps = tmp + dic[digits[curdep] - '0'][i];
            dfs(tmps,curdep + 1,depth,ans,dic,digits);
        }
        return ;
    }
};
