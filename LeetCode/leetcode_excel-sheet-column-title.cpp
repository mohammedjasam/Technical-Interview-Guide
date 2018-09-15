/*
*
* Tag: Math
* Time:lg(n)
* Space: O(1)
*/

class Solution {
private:
   char dict[26] = {'Z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y'};
public:
    string convertToTitle(int n) {
        string ans = "";
        while(n > 0){
            int idx = n%26;
            ans += dict[idx];
            if(n <= 26)
                break;
            int tmp_n = n;
            n /= 26;
            if(tmp_n%26 == 0)
                -- n;
        }
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};
