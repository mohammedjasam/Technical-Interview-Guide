/*
*
* Tag: DFS
* Time: O(2^n)
* Space: O(n)
*/
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        if(n <= 0){
            return ans;
        }
        
        dfs(0, 0, n, "", ans);
        return ans;
    }
    
private:
    void dfs(int numOfUsedLeftParenthesis, int numOfUsedRightParenthesis, int numOfTotalParenthesis, string parenthesis, vector<string> &ans){
        if(numOfUsedLeftParenthesis == numOfTotalParenthesis && numOfUsedRightParenthesis == numOfTotalParenthesis){
            ans.push_back(parenthesis);
            return ;
        }
        
        if(numOfUsedLeftParenthesis < numOfTotalParenthesis){
            dfs(numOfUsedLeftParenthesis + 1, numOfUsedRightParenthesis, numOfTotalParenthesis, parenthesis + "(", ans);
        }
        
        if(numOfUsedRightParenthesis < numOfUsedLeftParenthesis){
            dfs(numOfUsedLeftParenthesis, numOfUsedRightParenthesis + 1, numOfTotalParenthesis, parenthesis + ")", ans);
        }
    }
};
