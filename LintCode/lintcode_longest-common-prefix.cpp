/*
*
* Tag: Brute Force
* Time: O(nm) where m is the longest length
* Space: O(m)
*/
class Solution {
public:    
    /**
     * @param strs: A list of strings
     * @return: The longest common prefix
     */
    string longestCommonPrefix(vector<string> &strs) {
        // write your code here
        string ans = "";
        if(strs.size() == 0)
            return ans;
        string prefix = strs[0];
        ans = prefix;
        int n = strs.size();
        for(int i = 1; i < n; ++ i){
            ans = "";
            for(int j = 0; j < strs[i].size() && j < prefix.size(); ++ j){
                if(prefix[j] == strs[i][j])
                    ans += prefix[j];
                else
                    break;
            }
            if(ans == "")
                break;
            prefix = ans;
        }
        return ans;
    }
};
