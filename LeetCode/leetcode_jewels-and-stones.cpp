/*
*
* Tag: Hash
* Time: O(n)
* Space: O(n)
*/
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int ans = 0;
        if(J.size() == 0 || S.size() == 0){
            return ans;
        }
        
        unordered_set<char> jewels;
        for(int i = 0; i < J.size(); ++ i){
            jewels.insert(J[i]);
        }
        
        for(int i = 0; i < S.size(); ++ i){
            if(jewels.count(S[i]) != 0){
                ++ ans;
            }
        }
        
        return ans;
    }
};
