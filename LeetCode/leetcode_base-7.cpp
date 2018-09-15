/*
*
* Tag: Math
* Time: O(lgn)
* Space: O(1)
*/
class Solution {
public:
    string convertToBase7(int num) {
        string ans = "";
        if(num == 0){
            ans = "0";
            return ans;
        }
        int v = 0;
        bool isneg = false;
        if(num < 0){
            isneg = true;
            num = -num;
        }
        while(num > 0){
            v = num%7;
            num /= 7;
            ans += to_string(v);
        }
        if(isneg)
            ans += "-";
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
