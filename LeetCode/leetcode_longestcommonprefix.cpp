/*
* Algorithm: Brute force
* Time complexity: O(n^2)
* Memory complexity: O(1)
*/
class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        string ans="";
        if(strs.size() == 0) return ans;
        string tmp = "";
        int minlen = (1<<29);
        for(int i = 0; i < strs.size(); i ++){
            if(strs[i].length() < minlen){
                minlen = strs[i].length();
            }
        }
        for(int i = 0; i < minlen; i ++){
            int cnt = 1;
            for(int j = 0; j < strs.size(); j ++){
                if(j == 0){
                    tmp = strs[j][i];
                }else{
                    if(strs[j][i] == tmp[0]){
                        cnt++;
                    }
                    else{
                        break;
                    } 
                }
            }
            if(cnt == strs.size()){
                ans += tmp;
            }else{
                break;
            }
        }
        return ans;
    }
};
