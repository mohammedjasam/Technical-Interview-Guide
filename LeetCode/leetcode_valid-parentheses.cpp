/*
*
* Tag: Stack (Data Structure)
* Time: O(n)
* Space: O(n)
*/
class Solution {
public:
   bool isValid(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        stack<char> lefts;
        for(int i = 0 ; i < s.size() ;++i) {
            char c = s[i];
            if(c == '(' || c == '[' || c == '{') {
                lefts.push(c);
                continue;
            }
                
            if (lefts.empty()) {
                return false;
            }
                
            char top = lefts.top();
            if (c == ')') {
                if(top != '(') return false;
            } else if ( c == ']' ) {
                if(top != '[') return false;
            } else if ( c == '}' ){
                if(top != '{') return false;
            }

            lefts.pop();
        }
       
        return lefts.empty();
    }
};
