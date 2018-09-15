/*
*
* Tag: Data Structure (Stack)
* Time: O(n)
* Space: O(n)
*/
class Solution {
public:
    /**
     * @param s A string
     * @return whether the string is a valid parentheses
     */
    bool isValidParentheses(string& s) {
        // Write your code here
        if(!s.size())
            return true;
        int n = s.size(), top = 0;
        vector<char> stk(n);
        for(int i = 0; i < n; ++ i){
            if(!top){
                stk[top ++] = s[i];
                continue;
            }
            if((s[i] == ']') || (s[i] == '}') || (s[i] == ')')){
                char tp = stk[-- top];
                if((tp == '[' && s[i] == ']') || (tp == '{' && s[i] == '}') || (tp == '(' && s[i] == ')'))
                    continue;
                else
                    return false;
            }else{
                stk[top ++] = s[i];
            }
        }
        return !top;
    }
};
