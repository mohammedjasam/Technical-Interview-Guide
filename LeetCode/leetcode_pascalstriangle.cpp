/*
* Algorithm: Brute force
* Time complexity: O(n^2)
* Memory complexity: O(n^2)
*/
class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > ans(numRows, vector<int>(0));
        vector<vector<int> > zero;
        if(numRows == 0)
            return zero;
        ans[0].push_back(1);
        for(int i = 1; i < numRows; i ++){
            for(int j = 0; j <= ans[i - 1].size(); j ++){
                if(j == 0 || j == ans[i - 1].size())
                    ans[i].push_back(1);
                else{
                    ans[i].push_back(ans[i - 1][j -1] + ans[i - 1][j]);
                }
            }
        }
        return ans; 
    }
};

