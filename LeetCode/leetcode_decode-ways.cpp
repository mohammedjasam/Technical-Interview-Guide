/*
*
* Tag: DP
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    int numDecodings(string s) {
        if(s.size() == 0 || s[0] == '0'){
            return 0;
        }
        
        int cur = 1, prev = 0;
        
        for(int i = 1; i <= s.size(); i ++){
            if(s[i - 1] == '0'){
                cur = 0;
            }
            
            if(i < 2 || !(s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6'))){
                prev = 0;
            }
            
            int tmp = cur;
            cur += prev;
            prev = tmp;
        }
        
        return cur;
    }
};
