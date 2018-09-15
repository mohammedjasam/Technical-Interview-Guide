/*
*
* Tag: Implementation
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        vector<vector<int>> ans;
        if(S.size() == 0){
            return ans;
        }
        
        int startIndex = 0;
        for(int i = 0; i <= S.size(); ++ i){
            if(i == S.size() || S[startIndex] != S[i]){
                if(i - startIndex >= 3) {
                    int endIndex = i - 1;
                    ans.push_back({startIndex, endIndex});
                }
                
                startIndex = i;
            }
        }
        
        return ans;
    }
};
