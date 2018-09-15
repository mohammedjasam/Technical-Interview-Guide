/*
*
* Tag: Implementation
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    string addStrings(string num1, string num2) {
        int idx1 = num1.size() - 1, idx2 = num2.size() - 1, c = 0, sum = 0;
        string ans = "", tmp = "";
        while(idx1 >= 0 && idx2 >= 0){
            sum = (num1[idx1] - '0') + (num2[idx2] - '0') + c;
            tmp = (sum%10 + '0');
            ans = tmp + ans;
            c = sum/10;
            -- idx1, -- idx2;
        }
        while(idx1 >= 0){
            sum = (num1[idx1 --] - '0') + c;
            tmp = (sum%10 + '0');
            ans = tmp + ans;
            c = sum/10;
        }
        while(idx2 >= 0){
            sum = (num2[idx2 --] - '0') + c;
            tmp = (sum%10 + '0');
            ans = tmp + ans;
            c = sum/10;
        }
        if(c){
            tmp = (c + '0');
            ans = tmp + ans;
        }
        return ans;
    }
};
