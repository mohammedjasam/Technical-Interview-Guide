/*
*
* Tag: Two Pointers
* Time: O(n)
* Space: O(n)
*/

class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        vector<int> ans;
        if(S.size() == 0){
            return ans;
        }
        ans.resize(S.size());
        fill(ans.begin(), ans.end(), INT_MAX);
        
        vector<int> posOfCharacter;
        for(int i = 0; i < S.size(); ++ i){
            if(S[i] == C) {
                ans[i] = 0;
                posOfCharacter.push_back(i);
            }
        }
        
        int lastPosIndex = -1, curPosIndex = 0;
        for(int i = 0; i < S.size(); ++ i){
            if(S[i] == C){
                lastPosIndex = curPosIndex;
                ++ curPosIndex;
            } else {
                if(lastPosIndex != -1) {
                    ans[i] = abs(i - posOfCharacter[lastPosIndex]);
                }
                if(curPosIndex < posOfCharacter.size()) {
                    ans[i] = min(ans[i], abs(i - posOfCharacter[curPosIndex]));
                }
            }
        }
        
        return ans;
    }
};
