/*
*
* Tag: Greedy
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    vector<int> findPermutation(string s) {
        vector<int> ans;
        if(s.size() == 0)
            return ans;
        for(int i = 0; i <= s.size(); ++ i){
            if(i == s.size() || s[i] == 'I'){
                for(int j = i + 1, k = ans.size(); j > k; -- j){
                    ans.push_back(j);
                }
            }
        }
        return ans;
    }
};
