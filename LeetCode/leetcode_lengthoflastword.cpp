/*
* Algorithm: Brute force
* Time complexity: O(n)
* Memory complexity: O(1)
*/
class Solution {
public:
    int lengthOfLastWord(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(s[0]=='\0') return 0;
        int ans = 0, cnt = 0;
        for(int i = 0; s[i]!='\0'; i ++){
            if(s[i]==' '){
                if(cnt != 0) ans = cnt;
                cnt = 0;
            }else{
                cnt ++;
            }
        }
        if(cnt != 0) ans = cnt;
        return ans;
    }
};
