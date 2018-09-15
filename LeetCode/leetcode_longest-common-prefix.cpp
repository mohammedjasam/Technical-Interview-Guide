/*
*
* Tag: string (brute force)
* Time: O(n) where n is the number of characters of all the strings.
* Space: O(1)
*/

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        string ans="";
        if(strs.size() == 0) {
            return ans;
        }
        
        int minlen = INT_MAX;
        for(int i = 0; i < strs.size(); i ++){
            if(strs[i].length() < minlen){
                minlen = strs[i].length();
            }
        }
        
        char commonCharacter = 0;
        for(int i = 0; i < minlen; i ++){
            int cnt = 1;
            for(int j = 0; j < strs.size(); j ++){
                if(j == 0){
                    commonCharacter = strs[j][i];
                }else{
                    if(strs[j][i] == commonCharacter){
                        cnt++;
                    }
                    else{
                        break;
                    } 
                }
            }
            if(cnt == strs.size()){
                ans += commonCharacter;
            }else{
                break;
            }
        }
        
        return ans;
    }
};
