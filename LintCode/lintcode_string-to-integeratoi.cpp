/*
*
* Tag: Brute Force
* Time: O(n）
* Space: O(n)
*/
class Solution {
public:
    /**
     * @param str: A string
     * @return An integer
     */
    int atoi(string str) {
        // write your code here
        int res = 0, sign = 1;
        int len = str.size();
        int i = 0;
        bool hasplus = 0;
        while(str[i] == ' ' && i < len) ++ i;
        if(str[i] == '+'){
            ++ i;
            hasplus = true;
        }
        if(str[i] == '-'){
            if(hasplus)
                return 0;
            ++ i;
            sign = -1;
        }
        for(; i < len; ++ i){
            if(str[i] < '0' || str[i] > '9')
                break;
            if(res > INT_MAX/10 || (res == INT_MAX/10 && (str[i]-'0') >= INT_MAX))
                return sign == -1?INT_MIN : INT_MAX;
            res = res*10 + (str[i] - '0');
        }
        return res*sign;
    }
};
